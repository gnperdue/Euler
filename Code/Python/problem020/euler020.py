#!/usr/bin/env python
from __future__ import print_function
from scipy.misc import factorial


s = str(factorial(100, exact=True))
euler = 0
for c in s:
    euler += int(c)

print(euler)
