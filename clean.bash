#!/usr/bin/bash

cat $* \
    | sed '1,/START OF THIS PROJECT/d' \
    | ./expand_abbrev.sed \
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
    | sed -e 's/  */ /g' \
    | sed -e 's/[^[:print:]]//g' \
    | sed -e 's/www//g' \
    | sed -e 's/pgdp//g' \
    | sed -e 's/http//g' \
    | grep -v '<S> *<\/S>' \
    | ./delete_single_letter.sed \
    | tr -s ' ' \
    | tr -s '\n' 


#  | awk 'NF > 5'
# What does this do?