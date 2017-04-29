#!/usr/bin/python

import os
import time

os.system("set > real_env_var.txt")

no_diff = True

while no_diff:
    os.system("set > env_var.txt")
    os.system("diff -q real_env_var.txt env_var.txt > out.txt")
    if os.stat('out.txt').st_size == 0:
        time.sleep(2)
    else:
        with open('out.txt') as f:
            for line in f:
                print(line)
        no_diff = False


