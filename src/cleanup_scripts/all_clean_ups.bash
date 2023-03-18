# echo "Current directory:" $(pwd) # Q for prof: its obvious why it would write to file,
# but is there to write to cmd line?

cat $* \
    | ./upper_to_lower.bash \
    | ./precleanup.sed \
    | ./new_lines_to_@.bash \

