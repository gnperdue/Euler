#!/usr/bin/env python
import numpy as np


def seive2list(max):
    primes = np.array([2])
    raw = np.arange(3, max + 1)
    while raw.size > 0:
        primes = np.insert(primes, 0, raw[0])
        raw = raw[np.mod(raw, raw[0]) != 0]
    return primes


def seive2num(max):
    prime = 2
    raw = np.arange(3, max + 1)
    while raw.size > 0:
        prime = raw[0]
        raw = raw[np.mod(raw, raw[0]) != 0]
    return prime


def euler():
    primes = seive2list(2000000)
    return np.sum(primes)


if __name__ == '__main__':
    print "The sum of the primes below two million is %d" % euler()
