#!/usr/bin/env Rscript

bincoeff <- function(n,k) {
  factorial(n) / ( factorial(k) * factorial(n - k) )
}

ans <- bincoeff(40,20)
print(ans)
