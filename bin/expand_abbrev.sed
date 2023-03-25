#!/bin/sed -f
# create a script that expands Dr. into Doctor etc.
# it takes in from standard input and outputs to standard output

# the sed command is a regular expression

s/Dr\./Doctor/g
s/Mr\./Mister/g
s/Mrs\./Missus/g
s/Ms\./Miss/g
s/Prof\./Professor/g
s/St\./Saint/g
s/st\./street/g
s/ave\./avenue/g