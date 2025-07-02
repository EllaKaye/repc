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
  if (length(times) > 1 & length(times) != length(x)) {
    stop(
      "Either `times` must be a single integer or `x` and `times` must be the same length"
    )
  }

  if (length(each) != 1) {
    stop("`each` must be a single integer")
  }

  .Call(c_rep, as.numeric(x), as.integer(times), as.integer(each))
}
