#include <stddef.h>
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>


// TODO: add `each` arg
// MAYBE: add `length.out` arg
SEXP c_rep(SEXP x, SEXP times, SEXP each) {

  int each_c = Rf_asInteger(each);
  size_t length_x = XLENGTH(x);
  size_t length_times = XLENGTH(times);
  const double *xp = REAL(x);
  const int *timesp = INTEGER(times);
  
  size_t length_out = 0;
  if (length_times == 1) {
    length_out = length_x * timesp[0] * each_c; 
  } else if (length_times > 0 && each_c == 1) {
    for (size_t i = 0; i < length_times; i++) {
      length_out += timesp[i];
    }
  } else {
    Rprintf("Not a valid case: rep() would throw an error.");
    return R_NilValue;
  }

  SEXP out = PROTECT(Rf_allocVector(REALSXP, length_out));
  double *outp = REAL(out); 

  /*
  if (each_c == 1 && length_times == 1) {
    for (size_t i = 0; i < timesp[0]; i++) {
      for (size_t j = 0; j < length_x; j++) {
        outp[i * length_x + j] = xp[j];
      }
    }
  } else if (each_c > 1 && timesp[0] == 1 && length_times == 1) {
    for (size_t i = 0; i < length_x; i++) {
      for (size_t j = 0; j < each_c; j++) {
        outp[i * each_c + j] = xp[i];
      }
    }
  } else if (each_c > 1 && timesp[0] > 1 && length_times == 1) {
  */
  if (length_times == 1) {
    for (size_t i = 0; i < length_x; i++) {
        for (size_t j = 0; j < each_c; j++) {
            for (size_t k = 0; k < timesp[0]; k++) {
                outp[(i * each_c + j) + k * (length_x * each_c)] = xp[i];
            }
        }
    }
  } 
  else if (each_c == 1 && length_times > 1) {
    // must have length_times == length_x
    // get array of indices where we move to next element of x
    int change_indices[length_times];
    change_indices[0] = 0;
    for (size_t i = 0; i < length_times; i ++) {
      change_indices[i + 1] = change_indices[i] + timesp[i];
    }

    for (size_t i = 0; i < length_x; i++) {
        size_t start_idx = change_indices[i];
        size_t end_idx = (i == length_x - 1) ? length_out : change_indices[i + 1];
        
        // Fill this segment with xp[i] repeated (end_idx - start_idx) times
        for (size_t j = start_idx; j < end_idx; j++) {
            outp[j] = xp[i];
        }
    }
  }
  else {
    Rprintf("Haven't implemented this case");
    UNPROTECT(1);
    return R_NilValue;
  }

  UNPROTECT(1);

  return out;
}

