



# Usage:
# Classify a given text input by which author it is most likely to be written by.


classify () {
    # Get the text input from the user.
    echo "Enter the text to classify:"
    read text

    cat $text | tr '[:upper:]' '[:lower:]' | tr -d '[:punct:]' | tr -s ' ' '\n' | sort | uniq -c | sort -nr > $text.txt
}
