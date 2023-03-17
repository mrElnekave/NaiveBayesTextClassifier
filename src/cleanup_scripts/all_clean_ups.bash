# echo "Current directory:" $(pwd) # Q for prof: its obvious why it would write to file,
# but is there to write to cmd line?

pwd 
cat $* \
    | tr A-Z a-z \
    | ./precleanup.sed \

