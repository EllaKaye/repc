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
rep_c <- function(x, times) {
  # Do some checking on the arguments

  .Call(c_rep, x, times)
}
