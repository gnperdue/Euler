#!/usr/bin/env python

import triangularNumber


tn = triangularNumber.TriangularNumber(7)
tnum = tn.get()
tfac = tn.factors()
ntfac = tn.nfactors()

assert tnum == 28
assert ntfac == 6

tn.set(6)
tnum = tn.get()
ntfac = tn.nfactors()

assert tnum == 21
assert ntfac == 4
