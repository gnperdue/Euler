#!/usr/bin/env python

import pandas as pd
from pandas import Series, DataFrame

# don't use the first row as a header, set col "names" to be the numerical
# index, and specify that the separator is a simple space (not a tab)
data = pd.read_table("grid.txt", header=None, names=np.arange(20), sep=' ')
