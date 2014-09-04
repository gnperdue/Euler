#!/usr/bin/env Rscript

is.palindromic <- function(n) {
  if ( n <= 0 ) {
    FALSE
  }
  else {
    vec <- vector()
    while (n != 0) {
      rem <- n %% 10
      n <- n - rem
      n <- n / 10
      vec <- append(vec, rem)
    }
    identical(vec, rev(vec))
  }
}

vv <- vector()
for (i in c(900:999)) {
  for (j in c(900:999)) {
    vv <- append(vv, i*j)
  } 
}
vv <- rev(vv)

for (i in vv) { 
  if (is.palindromic(i)) { 
    print(i)
    break
  }
}
