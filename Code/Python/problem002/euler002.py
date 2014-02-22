#!/usr/bin/env python3


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


fibo = Fibo()

index = 0

max = 4000000

val = fibo.getFiboNumber(index)

while (val < max):
    fibo.addFiboNumber()
    index = index + 1
    val = fibo.getFiboNumber(index)

fibos = fibo.getFiboList()

sum = 0

for i in fibos:
    if i % 2 == 0:
        sum = sum + i

print("The sum is {0}".format(sum))
