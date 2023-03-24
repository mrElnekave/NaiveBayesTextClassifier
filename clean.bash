#!/usr/bin/bash

#| sed '1,/START OF THE PROJECT/d'     \

cat $* \
    | sed '1,/START OF THIS PROJECT/d' \
    | tr A-Z a-z \
    | tr -d '[",]' \
    | sed -e 's/[.] */.~/g' \
    | sed -e  's/[-—]/ /g' \
    | tr \\n ' ' \
    | tr -d \\r \
    | tr '~' '\n' \
    | sed -e 's/  */ /g' \
    | sed -e 's/[.?!:]/\n/g' \
    | sed -e 's/[_/()]//g' \
    | sed -e 's/^ *//' \
    | sed -e 's/ *$//' \
    | tr -s '\n' \
    | sed -e 's/^/<S> /' -e 's#$# </S>#' \
    | grep -v '^<S>\s*</S>$' \
    | sed -e 's/[^[:print:]]//g' \
    | sed -e 's/www//g' \
    | sed -e 's/pgdp//g' \
    | sed -e 's/http//g' 


#  | awk 'NF > 5'
# I have no idea what this does so i just commented it out :D