#!/usr/bin/env python

import numpy as np


def get_square_array(min_v, max_v):
    amat = np.mat(np.zeros((max_v - min_v + 1, max_v - min_v + 1)))
    amat[:, :] = np.arange(min_v, max_v + 1)
    return (amat.T).A ** (amat).A


def euler(min_v, max_v):
    return len(np.unique(get_square_array(min_v, max_v).flatten()))


if __name__ == '__main__':
    minv = 2
    maxv = 100
    print "Consider the square array built for:"
    print "  %d <= a <= %d, and %d <= b <= %d" % (minv, maxv, minv, maxv)
    ans = euler(minv, maxv)
    print "There are %d unique terms for the matrix a^b." % ans
