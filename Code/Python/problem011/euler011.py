#!/usr/bin/env python

import numpy as np
import pandas as pd
from pandas import Series


# don't use the first row as a header, set col "names" to be the numerical
# index, and specify that the separator is a simple space (not a tab)
def get_the_data():
    data = pd.read_table("grid.txt", header=None, names=np.arange(20), sep=' ')
    return data

# strategy - do four passes over the data, one for the vertical, one for the
# horizontal, and one for each diagonal. on the loop, compute the largest
# product of four consecutive numbers.


# test the vertical and horizontal first
def scan(data_frame):
    largest_product = 0
    for i in data_frame.index:
        s = Series(data_frame.ix[i, :])
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    for i in data_frame.columns:
        s = Series(data_frame.ix[:, i])
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    print "the largest overall product is %d" % largest_product
    # next test the diagonals
    return largest_product


# do just a generic Series
def get_largest_product(ser):
    maxlen = 4 if (ser.size > 3) else ser.size
    print "max length = %d" % maxlen
    largest_product = 0
    for i in ser.index:
        local_product = ser[i]
        print "i, local_product = %d, %d" % (i, local_product)
        if i + maxlen > ser.size:
            print "max len extends beyond the end of the series"
            maxlen = ser.size - i
            print " new max length = %d" % maxlen
        for j in ser[i + 1: i + maxlen]:
            local_product *= j
            print " j, local_product = %d, %d" % (j, local_product)
        if local_product > largest_product:
            largest_product = local_product
            print "new largest product = %d" % largest_product
    return largest_product



# mylist = []
# mylist.append(df.ix[0,0])
# mylist.append(df.ix[1,1])
# mylist.append(df.ix[2,2])
# arr0 = np.array(mylist)
# or
# ser0 = Series(mylist)
# s = Series(df.ix[:,0])
