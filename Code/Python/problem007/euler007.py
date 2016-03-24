#!/usr/bin/env python
from __future__ import print_function
import math


def check_prime(number):
    sqrt_num = math.sqrt(number)
    float_num = float(number)
    for i in range(2, int(sqrt_num) + 1):
        if (float_num / i).is_integer():
            return False
    return True


def get_nth_prime(n):
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    if n <= 10:
        return primes[n - 1]
    else:
        count = 10
        test = 30
        while True:
            if check_prime(test):
                count += 1
                if count == n:
                    return test
            test += 1


if __name__ == '__main__':
    print("The answer is %d" % get_nth_prime(10001))
