#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

SEXP c_rle(SEXP x, SEXP times) {

  size_t length = XLENGTH(x) * Rf_asReal(times);

  SEXP out = PROTECT(Rf_allocVector(REALSXP, length));

  // for now, assume length(x) = 1
  for (size_t i = 0; i < length; ++i) {
    REAL(out)[i] = Rf_asReal(x);
  }

  UNPROTECT(1);

  return out;
}
