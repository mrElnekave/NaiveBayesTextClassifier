# echo "Current directory:" $(pwd) # Q for prof: its obvious why it would write to file,
# but is there to write to cmd line?

cat $* \
    | ./precleanup.sed \
    | ./new_lineNspaces.bash \
    | ./upper_to_lower.bash \

# change this so that it will run the correct scripts no matter where the script is run from
# Q for prof: is there a way to do this without hardcoding the path?

# cat $* \
#     | ./src/cleanup_scripts/precleanup.sed \
#     | ./src/cleanup_scripts/new_lineNspaces.bash \
#     | ./src/cleanup_scripts/upper_to_lower.bash \
