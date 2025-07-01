#' Repeat a vector
#'
#' `rep_c()` repeats a vector
#'
#' @param x A single numeric value
#' @param times A single numeric value
#'
#' @examples
#' rep_c(1, 3)
#'
#' @export
#'
rep_c <- function(x, times = 1, each = 1) {
  # Do some checking on the arguments

  if (is.integer(x)) {
    x <- as.numeric(x)
  }

  if (!is.integer(each)) {
    each <- as.integer(each)
  }

  .Call(c_rep, x, times, each)
}
