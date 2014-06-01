#!/usr/bin/env python

import numpy as np
from pandas import Series


def collatz_length(num):
    start = num
    leng = 0
    if num > 0:
        leng += 1
        while num > 1:
            leng += 1
            if num % 2 == 0:
                num /= 2
            else:
                num = 3 * num + 1
    return (leng, start)


def euler(max_num):
    # Series max takes the first element in the tuple. how to use a custom fn?
    indx = Series(np.arange(max_num + 1))
    cols = indx.apply(collatz_length)
    (maxl, maxi) = cols.max()
    print "The longest Collatz sequence is for %d = %d" % (maxi, maxl)

if __name__ == '__main__':
    euler(1000)
