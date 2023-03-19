#!/usr/bin/python3
import subprocess
import random

MIN = 0
MAX = 100000
N = 3000

cmd = ""
for i in range(N):
	cmd += str(random.randint(MIN, MAX)) + " "
#print(cmd)
out = subprocess.check_output(("./PmergeMe "+cmd).split()).decode()

o = out[out.find("After: ")+6:out.find("Time")]
o = [int(v) for v in o.split()]
print(o)
print(o == sorted(o))