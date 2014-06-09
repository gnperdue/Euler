#!/usr/bin/env python

the_sum = 0
with open("nums.txt", "r") as the_file:
    for line in the_file:
        num = int(line)
        the_sum += num

print str(the_sum)[:10]
