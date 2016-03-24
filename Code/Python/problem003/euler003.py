#!/usr/bin/env python
from __future__ import print_function
import math

theNumber = 600851475143


def startingPoint(num):
    start = math.floor(math.sqrt(num))
    print("The starting point is {0}".format(start))
    return start


def isprime(num):
    factor = num - 1
    while (factor > 1):
        if num % factor == 0:
            return False
        factor = factor - 1
    return True


def euler(num, test):
    while test > 0:
        if num % test == 0 and isprime(test):
            print("The largest prime factor is {0}".format(test))
            return test
        test = test - 1


if __name__ == '__main__':
    euler(theNumber, startingPoint(theNumber))
