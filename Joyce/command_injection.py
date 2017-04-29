#!/usr/bin/python
import sys

def command_injection_with_argv(string, argvs):

    isstringvalid = True

    for argv in argvs:
        if argv in string.lower():
            isstringvalid = False

    return isstringvalid

def command_injection_without_argv(string):     #default

    argvs = [
        ";",

        #......
    ]

    isstringvalid = True

    for argv in argvs:
        #print argv
        if argv in string.lower():
            isstringvalid = False

    return isstringvalid

# command: python sql_injection.py "foo; rm" ";"
if __name__ == "__main__":
#    print sys.argv[0]
#    print sys.argv[1]
#    print sys.argv[2]
    argv_length = len(sys.argv)
#    print argv_length

    if argv_length < 2:
        print "command: python command_injection.py <original_code> key_word_1 key_word_2 ..."
        exit(1)

    string = sys.argv[1]

    if argv_length == 2:
        result = command_injection_without_argv(string)
    else:
        result = command_injection_with_argv(string, sys.argv)

    if (result):
        print string