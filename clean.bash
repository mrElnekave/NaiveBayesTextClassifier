#!/usr/bin/bash



cat $* \
    | sed '1,/START OF THIS PROJECT/d' \
    | tr A-Z a-z \
    | tr -d '[",]' \
    | sed -e 's/[.] */.~/g' \
    | sed -e  's/[-—]/ /g' \
    | tr \\n ' ' \
    | tr -d \\r \
    | tr '~' '\n' \
    | sed -e 's/[.?!:]/\n/g' \
    | sed -e 's/[_/()]//g' \
    | sed -e 's/^ */<S> /' \
    | sed -e 's# *$# </S>#' \
    | tr -s '\n' \
    | sed -e 's/  */ /g' \
    | sed -e 's/[^[:print:]]//g' \
    | sed -e 's/www//g' \
    | sed -e 's/pgdp//g' \
    | sed -e 's/http//g' \
    | ./delete_single_letter.bash

#line 19 needs fix

#  | awk 'NF > 5'
# I have no idea what this does so i just commented it out :D