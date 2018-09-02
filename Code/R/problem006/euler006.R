#!/usr/bin/env Rscript

sum.of.squares <- function(n) {
  if (n <= 0) {
    0
  }
  else {
    vv <- 1:n
    sum(sapply(vv, function(x){x^2}))
  }
}

square.of.sums <- function(n) {
  x <- sum(1:n)
  x^2
}

diff.of.squares <- function(n) {
  sqos <- square.of.sums(n)
  sosq <- sum.of.squares(n)
  sqos - sosq
}


