#!/usr/bin/python
import sys

def sql_injection_with_argv(string, argvs):

    isstringvalid = True

    for argv in argvs:
        if argv in string.lower():
            isstringvalid = False

    return isstringvalid

def sql_injection_without_argv(string):     #default

    argvs = [
        "'",
        "or",
        "and",
        "update",
        "select",
        "delete",
        "create"
        #......
    ]

    isstringvalid = True

    for argv in argvs:
        #print argv
        if argv in string.lower():
            isstringvalid = False

    return isstringvalid

# command: python sql_injection.py "example.com AND 1=1" AND
if __name__ == "__main__":
#    print sys.argv[0]
#    print sys.argv[1]
#    print sys.argv[2]
    argv_length = len(sys.argv)
#    print argv_length

    if argv_length < 2:
        print "command: python sql_injection.py <original_code> key_word_1 key_word_2 ..."
        exit(1)

    string = sys.argv[1]

    if argv_length == 2:
        result = sql_injection_without_argv(string)
    else:
        result = sql_injection_with_argv(string, sys.argv)

    if (result):
        print string

