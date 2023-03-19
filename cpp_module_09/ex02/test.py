#!/usr/bin/python3
import subprocess
import random

MIN = 0
MAX = 10000
N = 1000

cmd = ""
for i in range(N):
	cmd += str(random.randint(MIN, MAX)) + " "
#print(cmd)
out = subprocess.check_output(("./PmergeMe "+cmd).split())
for o in out.decode().split('|'):
	#print(cmd)
	#print(o)
	o = [int(v) for v in o.split()]
	print(o == sorted(o))