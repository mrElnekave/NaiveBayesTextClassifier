#!/usr/bin/sed -f

s/\n/ /
s/[.]  /\n/g 
/^[ \t][ \t]*$/d
s/[ \t][ \t]*/ /g
s/^/<S> /g 
s@$@ </S> @g

