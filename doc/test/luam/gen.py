#!/usr/bin/python

import random
import string

m = 5000
print m

sizes = [1, 5, 10, 50, 100, 250, 505, 1501, 2000, 2500, 3000, 3500, 4000, 4500, 5000]

for i in sizes:

	s = ''.join([random.choice(string.letters) for j in xrange(i)])
	print s.lower()
