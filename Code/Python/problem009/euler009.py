#!/usr/bin/env python
from __future__ import print_function
import pythagTriple


def euler():
    retvals = []
    for i in range(1, 1001):
        for j in range(i, 1001):
            for k in range(j, 1001):
                if (i + j + k == 1000):
                    p = pythagTriple.PythagTriple(i, j, k)
                    if p.isPythagorean():
                        print("Magic Triple: %d, %d, %d" % (i, j, k))
                        retvals.append(i * j * k)
    return retvals

if __name__ == '__main__':
    tripleProducts = euler()
    for i in tripleProducts:
        print("Triple product = %d" % i)
