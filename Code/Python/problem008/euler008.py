#!/usr/bin/env python
from __future__ import print_function
from six.moves import range


def get_product(list_of_stringnumbers):
    value = 1
    for s in list_of_stringnumbers:
        value *= int(s)
    return value


fr = open('numbers.txt', 'r')
nums = []
for line in fr.readlines():
    nums.extend(line.strip('\n'))

fr.close()

largest_prod = 1
for i in range(len(nums)):
    prod = get_product(nums[i:i + 13])
    if prod > largest_prod:
        largest_prod = prod

print("The largest product is {}".format(largest_prod))
