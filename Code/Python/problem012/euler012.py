#!/usr/bin/env python

import triangularNumber


def euler(cut=10):
    num = 12374  # the answer is 12375
    tn = triangularNumber.TriangularNumber(num)
    while tn.nfactors() < cut:
        num += 1
        tn.set(num)

    print "The first triangular number with %d factors is %d" % \
        (cut, tn.get())

if __name__ == '__main__':
    euler(500)
