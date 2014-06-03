#!/usr/bin/env python

if __name__ == '__main__':
    sum = 0
    for i in str(2 ** 1000):
        sum += int(i)
    print sum
