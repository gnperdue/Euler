#!/usr/bin/env python
from __future__ import print_function


class Fibo():
    def __init__(self):
        self.fiboList = [1]

    def addFiboNumber(self):
        l = len(self.fiboList)
        if 0 == l:
            self.fiboList = [1]
        elif 1 == l:
            self.fiboList = [1, 1]
        else:
            self.fiboList.append(self.fiboList[l - 1] + self.fiboList[l - 2])

    def getFiboNumber(self, index):
        return self.fiboList[index]

    def getFiboList(self):
        return self.fiboList


def countDigits(n):
    count = 0
    while n > 0:
        count += 1
        n = n // 10
    return count


fibo = Fibo()
index = 0
val = fibo.getFiboNumber(index)
ndigits = countDigits(val)

while (ndigits < 1000):
    index = index + 1
    fibo.addFiboNumber()
    val = fibo.getFiboNumber(index)
    ndigits = countDigits(val)

print(val)
print(index + 1)
print(ndigits)
