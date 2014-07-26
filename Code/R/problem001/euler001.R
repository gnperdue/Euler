#!/usr/bin/env Rscript

answer <- 0
for (i in 3:999) {
  if ( (i %% 3 == 0) || (i %% 5 == 0) ) answer <- answer + i
}
print(answer)
