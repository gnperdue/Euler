#!/usr/bin/env python

from scipy.special import binom as bincoeff
import numpy as np

if __name__ == '__main__':
    num_paths = bincoeff(40, 20)
    print "The number of paths is %d" % np.ceil(num_paths)
