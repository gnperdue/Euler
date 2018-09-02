#!/usr/bin/env Rscript

digit.list <- function(n) {
  vec <- vector()
  if ( n <= 0 ) {
    vec  
  }
  else {
    while (n != 0) {
      rem <- n %% 10
      n <- n - rem
      n <- n / 10
      vec <- append(vec, rem)
    }
    rev(vec)
  }
}

euler016 <- function(n) {
  sum( digit.list(n) )
}

# Need a BigInt for R...
#print( euler016(2^1000) )
print( euler016(2^10) )
