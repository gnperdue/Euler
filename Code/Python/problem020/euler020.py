#!/usr/bin/env python

from scipy.misc import factorial


s = str(factorial(100, exact=True))
euler = 0
for c in s:
    euler += int(c)

print euler
