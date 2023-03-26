#!/bin/sh

cat $* \
    | sed '1,/START/d' \
    | tr A-Z a-z \
    | tr -d '[",]' \
    | ./expand_abbrev.sed \
    | sed -e 's/[.] */.~/g' \
    | sed -e  's/[-—+]/ /g' \
    | tr \\n ' ' \
    | tr -d \\r \
    | tr '~' '\n' \
    | sed -e 's/[.?!:]/\n/g' \
    | sed -e 's/[_/()\$#]//g' \
    | sed -e 's/^ */<S> /' \
    | sed -e 's# *$# </S>#' \
    | sed -e 's/  */ /g' \
    | sed -e 's/[^[:print:]]//g' \
    | sed -e 's/www//g' \
    | sed -e 's/pgdp//g' \
    | sed -e 's/http//g' \
    | grep -v '<S> *<\/S>' \
    | tr -s ' ' \
    | tr -s '\n' \
    | ./delete_single_letter.sed \
    | awk 'NF > 5'

# What does "awk 'NF > 5'" do?