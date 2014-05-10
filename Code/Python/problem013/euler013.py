#!/usr/bin/env python

the_file = open("nums.txt", "r")
the_sum = 0
for line in the_file:
    num = int(line)
    the_sum += num

print str(the_sum)[:10]
