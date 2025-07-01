test_that("rep_c works with each = 1, length(times) = 1", {
  expect_equal(rep_c(1:3, times = 2), rep(1:3, times = 2))
})

test_that("rep_c works with each > 1, times = 1", {
  expect_equal(rep_c(1:3, each = 2), rep(1:3, each = 2))
})

test_that("rep_c works with each > 1, times > 1, length(times) = 1", {
  expect_equal(rep_c(1:3, times = 2, each = 2), rep(1:3, times = 2, each = 2))
})

test_that("rep_c works with length(times) > 1, each = 1", {
  expect_equal(rep_c(1:3, times = 1:3), rep(1:3, times = 1:3))
})
