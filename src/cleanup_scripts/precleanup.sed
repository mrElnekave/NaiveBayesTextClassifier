#!/usr/bin/sed -f

/^ *$/d
s/[.]  / /g 
/^[ \t][ \t]*$/d
s/[ \t][ \t]*/ /g
