#!/usr/bin/env python

# Forum solution; obvious to use sets...
print len(set(a**b for a in range(2, 101) for b in range(2, 101)))
