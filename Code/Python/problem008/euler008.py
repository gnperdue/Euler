#!/usr/bin/env python


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
    prod = get_product(nums[i:i + 5])
    if prod > largest_prod:
        largest_prod = prod

print "The largest product is %d\n" % largest_prod
