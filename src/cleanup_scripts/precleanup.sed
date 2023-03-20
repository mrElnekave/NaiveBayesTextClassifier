#!/usr/bin/sed -f

# delete all the start until the first ***
# using this regex ^[\s\S]*\*\*\*
s/^[\s\S]*\*\*\*//g


# Save only letters, spaces, and dashes
# s/ means substitute
# /g means apply to all occurrences
s/[^A-Za-z0-9 -']/ /g


