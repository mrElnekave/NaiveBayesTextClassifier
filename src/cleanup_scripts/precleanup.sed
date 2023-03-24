#!/usr/bin/sed

# delete all the start until the first ***
# using this regex ^[\s\S]*\*\*\*
# 1,/^[\s\S]*[*][*][*] START OF THIS PROJECT/d

1,/[. ]*/d

# Save only letters, spaces, and dashes
# s/ means substitute
# /g means apply to all occurrences

s/^[\s-]*$



