#!/usr/bin/env python

import numpy as np


def has_unique_digits(num):
    list_of_digits = []
    temp_num = num
    while temp_num > 0:
        last_digit = temp_num % 10
        temp_num -= last_digit
        temp_num /= 10
        list_of_digits.append(last_digit)

    return len(np.unique(list_of_digits)) == len(list_of_digits)


def is_list_of_unique_digits(list_of_nums):
    fullstr = str()
    for i in list_of_nums:
        fullstr += str(i)

    return has_unique_digits(int(fullstr))


def is_pandigital_list(list_of_nums):
    fullstr = str()
    for i in list_of_nums:
        fullstr += str(i)

    list_of_chars = list(fullstr)
    for c in list_of_chars:
        if int(c) == 0:
            return False
    return has_unique_digits(int(fullstr)) and len(fullstr) == 9


def is_pandigital_group(num):
    if not has_unique_digits(num):
        return False
    for multiplicand in range(2, num):
        if num % multiplicand == 0:
            multiplier = num / multiplicand
            if is_pandigital_list([multiplicand,
                                   multiplier,
                                   num]):
                print [multiplicand, multiplier, num]
                return True
    return False


def get_list_of_pandigitals(max):
    list_of_pandigitials = []
    for i in range(2, max + 1):
        if is_pandigital_group(i):
            list_of_pandigitials.append(i)

    return list_of_pandigitials


def get_pandigital_sum(max):
    pandigital_list = get_list_of_pandigitals(max)
    return np.sum(pandigital_list)


def euler():
    return get_pandigital_sum(9999)


if __name__ == '__main__':
    print euler()
