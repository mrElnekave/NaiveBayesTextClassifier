# echo "Current directory:" $(pwd) # Q for prof: its obvious why it would write to file,
# but is there to write to cmd line?

cat $* \
    | ./precleanup.sed \
    | ./new_lineNspaces.bash \
    | ./upper_to_lower.bash \


