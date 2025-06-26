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
rep_c <- function(x, times = 1) {
  # Do some checking on the arguments

  if (is.integer(x)) {
    x <- as.numeric(x)
  }

  .Call(c_rep, x, times)
}

rep_check <- function(x, times = 1) {
  length_x <- length(x)

  for (i in (seq_len(times) - 1)) {
    for (j in (seq_along(x) - 1)) {
      print(paste(
        "i: ",
        i,
        "j:",
        j,
        "i * length_x + j:",
        i * length_x + j
      ))
    }
  }
}
