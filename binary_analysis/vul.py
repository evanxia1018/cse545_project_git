#!/usr/bin/python

import os
import sys

def dump_file(filename):
    os.system("objdump -d "+filename+" > dump.txt")

def search_vul(dump_file):
    Enter_text = False
    with open(dump_file) as f:
        for line in f:
            if not Enter_text:
                if 'Disassembly of section .text' in line:
                    Enter_text = True
            elif '__stack_chk_fail' in line:
                print('There is stack smashing protection?')
            else :
                contains_vul(line)

def contains_vul(line):
    if 'strcpy' in line:
        print('strcpy vulnerability at :' +line )
    elif 'strcat' in line:
        print('overflowing vulnerability at :'+line)
    elif 'sprintf' in line:
        print('format string vulnerability at :'+line)
    elif 'printf' in line:
        print('format string vulnerability at :'+line)
    elif 'scanf' in line:
        print('Format string  vulnerability at :'+line)
    elif 'sprintf' in line:
        print('format string vulnerability at :'+line)
    elif 'snprintf' in line:
        print('Command injection or format string at :' +line)
    elif 'fprintf' in line:
        print('Format string vulnerability at' +line)
    elif '__stack_chk_fail' in line:
        print('There is stack smashing protection?')
    elif 'execlp' in line:
        print('command injection vulneribility at :' +line)



dump_file(sys.argv[1])
search_vul('dump.txt')
