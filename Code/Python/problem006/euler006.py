#!/usr/bin/env python
import numpy as np


def sum_of_squares(max):
    """square the numbers from 1 to max, inclusive, and sum them"""
    return np.square(np.arange(1, max + 1)).sum()


def square_of_sum(max):
    """square the sum of the numbers from 1 to max, inclusive"""
    return np.square(np.arange(1, max + 1).sum())


def euler(max):
    return square_of_sum(max) - sum_of_squares(max)


if __name__ == '__main__':
    print "The answer is %d" % euler(100)
