
# possible buffer overflow
error_functions = ["strcpy",
                   "printf", "fprintf", "sprintf",
                   "gets", "puts",
                   "strcat"]

# possible command line errors
command_line_functions = ["system",
                          "popen",
                          "execl", "execlp", "execle", "execv", "execvp", "execvpe", "execve"]

fileName = raw_input('Enter your filename:')
lineNumber = 0

with open(fileName) as f:
    for line in f:
        lineNumber += 1

        for function in error_functions:
            if function in line:
                print "Possible Buffer Overflow Attack"
                print str(lineNumber) + " " + line

        for function in command_line_functions:
            if function in line:
                print "Possible Command Line Injection/Dot Dot Attack/ Symbolic Link Attack"
                print str(lineNumber) + " " + line


