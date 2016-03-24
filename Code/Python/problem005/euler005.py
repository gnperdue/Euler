#!/usr/bin/env python
from __future__ import print_function
import numpy as np

testList = np.array([7, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])


def euler(testnum):
    while any(np.mod(testnum, testList)):
        testnum += 1
    return testnum


if __name__ == '__main__':
    answer = euler(20)
    print(answer)
