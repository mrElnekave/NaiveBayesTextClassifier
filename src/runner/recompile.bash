# recompile all our c++ files and name the exucutable the exact same name as the file.exe

for file in *.cpp
do
    # Get the name of the author from the name of the text file.
    name=$(basename $file .cpp)
    # Run the cleanup scripts on the text file.
    g++ $file -o $name.exe
    echo "done with" $name

done