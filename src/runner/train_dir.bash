# For each text file in the directory, run the cleanup scripts on it and then train the program on it.

echo "Training on all files in" $1
for file in $1/*.txt
do
    # Get the name of the author from the name of the text file.
    author=$(basename $file)
    # Run the cleanup scripts on the text file.
    echo "running" $author
    cat $file | ../cleanup_scripts/all_clean_ups.bash | ./train_model.exe -Author=$author
    echo "done with" $author

done

