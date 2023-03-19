#!/usr/bin/sed -f

# This is and .sed script to get rid of all the extra spaces in a file

#/^ *$/d
#s/[.]  / /g 
#/^[ \t][ \t]*$/d
#s/[ \t][ \t]*/ /g


# Save only letters, spaces, and dashes
# s/ means substitute
# /g means apply to all occurrences
s/[^A-Za-z -]/ /g
