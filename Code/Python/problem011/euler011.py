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
    largest_product = np.max(np.array([get_vert(data_frame),
                                       get_horiz(data_frame),
                                       get_nw_to_se(data_frame),
                                       get_se_to_nw(data_frame),
                                       get_sw_to_ne(data_frame),
                                       get_ne_to_sw(data_frame)
                                       ]))
    print "the largest overall product is %d" % largest_product


def get_vert(data_frame):
    largest_product = 0
    for i in data_frame.index:
        s = Series(data_frame.ix[i, :])
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


def get_horiz(data_frame):
    largest_product = 0
    for i in data_frame.columns:
        s = Series(data_frame.ix[:, i])
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


def get_nw_to_se(data_frame):
    largest_product = 0
    (x, y) = np.shape(data_frame)
    for j in range(19):
        k = 0
        lst = []
        lst.append(data_frame.ix[j, k])
        while j > 0:
            j -= 1
            k += 1
            lst.append(data_frame.ix[j, k])
        s = Series(lst)
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


def get_se_to_nw(data_frame):
    largest_product = 0
    (x, y) = np.shape(data_frame)
    for j in reversed(range(19)):
        k = 19
        lst = []
        lst.append(data_frame.ix[j, k])
        while j < 19:
            j += 1
            k -= 1
            lst.append(data_frame.ix[j, k])
        s = Series(lst)
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


def get_sw_to_ne(data_frame):
    largest_product = 0
    (x, y) = np.shape(data_frame)
    for j in reversed(range(19)):
        k = 0
        lst = []
        lst.append(data_frame.ix[j, k])
        while j < 19:
            j += 1
            k += 1
            lst.append(data_frame.ix[j, k])
        s = Series(lst)
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


def get_ne_to_sw(data_frame):
    largest_product = 0
    (x, y) = np.shape(data_frame)
    for j in range(19):
        k = 19
        lst = []
        lst.append(data_frame.ix[j, k])
        while j > 0:
            j -= 1
            k -= 1
            lst.append(data_frame.ix[j, k])
        s = Series(lst)
        local_product = get_largest_product(s)
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


# do just a generic Series
def get_largest_product(ser):
    maxlen = 4 if (ser.size > 3) else ser.size
    largest_product = 0
    for i in ser.index:
        local_product = ser[i]
        if i + maxlen > ser.size:
            maxlen = ser.size - i
        for j in ser[i + 1: i + maxlen]:
            local_product *= j
        if local_product > largest_product:
            largest_product = local_product
    return largest_product


if __name__ == '__main__':
    scan(get_the_data())
