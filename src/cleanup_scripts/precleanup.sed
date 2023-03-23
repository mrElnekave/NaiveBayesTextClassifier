#!/usr/bin/sed

# delete all the start until the first ***
# using this regex ^[\s\S]*\*\*\*
# s/^[\s\S]*[*][*][*] START OF THIS PROJECT//g

1,/[. ]*/d

# Save only letters, spaces, and dashes
# s/ means substitute
# /g means apply to all occurrences

s/^[\s-]*$



