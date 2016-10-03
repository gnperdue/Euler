#!/usr/bin/env python
from __future__ import print_function
import pandas as pd


if __name__ == '__main__':
    count = 0
    index = pd.date_range('1/1/1901', '12/31/2000', freq='WOM-1SUN')
    for i in index:
        if i.day == 1:
            count += 1

    print("The number of months start on a Sunday in the 20th Century was:")
    print(count)
