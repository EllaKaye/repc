#include <stddef.h>
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>


// TODO: add `each` arg
// MAYBE: add `length.out` arg
SEXP c_rep(SEXP x, SEXP times, SEXP each) {

  // for now assume times is a single numeric
  // TODO: allow times to be a vector
  int times_c = Rf_asInteger(times);
  int each_c = Rf_asInteger(each);
  size_t length_x = XLENGTH(x);
  size_t length_times = XLENGTH(times);
  size_t length_out = length_x * times_c * each_c;
  const double *xp = REAL(x);

  SEXP out = PROTECT(Rf_allocVector(REALSXP, length_out));
  double *outp = REAL(out); 

  if (each_c == 1 && length_times == 1) {
    for (size_t i = 0; i < times_c; i++) {
      for (size_t j = 0; j < length_x; j++) {
        outp[i * length_x + j] = xp[j];
      }
    }
  } else if (each_c > 1 && times_c == 1 && length_times == 1) {
    for (size_t i = 0; i < length_x; i++) {
      for (size_t j = 0; j < each_c; j++) {
        outp[i * each_c + j] = xp[i];
      }
    }
  } else if (each_c > 1 && times_c > 1 && length_times == 1) {
    for (size_t i = 0; i < length_x; i++) {
        for (size_t j = 0; j < each_c; j++) {
            for (size_t k = 0; k < times_c; k++) {
                outp[(i * each_c + j) + k * (length_x * each_c)] = xp[i];
            }
        }
    }
  } 
  else {
    Rprintf("Haven't dealt with this case yet");
  }

  UNPROTECT(1);

  return out;
}

