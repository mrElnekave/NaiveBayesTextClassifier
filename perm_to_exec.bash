# give all bash scripts in the current directory and subdirectories permission to execute

for file in $(find . -name "*.sh"); do
    chmod u+x $file
done
