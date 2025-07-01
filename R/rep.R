#' Repeat a vector
#'
#' `rep_c()` repeats a vector
#'
#' @param x A single numeric value
#' @param times An integer vector
#' @param each A single integer value
#'
#' @examples
#' rep_c(1, 3)
#'
#' @export
#'
rep_c <- function(x, times = 1, each = 1) {
  # TODO: some checking on the arguments

  if (is.integer(x)) {
    x <- as.numeric(x)
  }

  if (!is.integer(times)) {
    times <- as.integer(times)
  }

  if (!is.integer(each)) {
    each <- as.integer(each)
  }

  .Call(c_rep, x, times, each)
}
