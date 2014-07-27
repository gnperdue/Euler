#!/usr/bin/env python

import numpy as np


def proper_divisors(n):
    ar = np.arange(1, n)
    return ar[n % ar == 0]


def prop_div_sum(n):
    return np.sum(proper_divisors(n))


def is_amicable_pair(m, n):
    if m == prop_div_sum(n) and n == prop_div_sum(m):
        return True
    return False


def get_amicables_vect(n):
    vfunc = np.vectorize(is_amicable_pair)
    pairs = []
    for i in np.arange(1, n + 1):
        arr = np.arange(i + 1, n + 1)
        if len(arr) > 0:
            tvals = vfunc(arr, i)
            if tvals.any():
                inds = np.where(tvals == True)[0]
                vals = arr[inds]
                for num in vals:
                    pairs.extend((num, i))
    return pairs


def get_amicables_list(n):
    all_nums = range(2, n + 1)
    pairs = []
    while len(all_nums) > 0:
        test = all_nums[0]
        all_nums.remove(test)
        a = prop_div_sum(test)
        if prop_div_sum(a) == test and a != test:
            pairs.extend([a])
            pairs.extend([test])
            all_nums.remove(a)
    return pairs


def euler_vect():
    return np.sum(get_amicables_vect(10000))


def euler_list():
    return np.sum(get_amicables_list(10000))


if __name__ == '__main__':
    print euler_list()
