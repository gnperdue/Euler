#!/usr/bin/env python3
import numpy as np


def is_evenly_div_by_all(testnum, numlist):
    return 0 == np.mod(testnum, numlist).sum()


def euler(testnum):
    testList = np.array([7, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
    while not is_evenly_div_by_all(testnum, testList):
        testnum += 1
    return testnum


if __name__ == '__main__':
    answer = euler(20)
    print(answer)
