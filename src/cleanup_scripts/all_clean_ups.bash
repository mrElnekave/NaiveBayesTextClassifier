#!/usr/bin/bash

export $PATH
# PATH=/mnt/c/Users/Nathan/Documents/GitHub/NaiveBayesTextClassifier/NaiveBayesTextClassifier/src/cleanup_scripts:$PATH
PATH=C:/Users/klavl/Documents/GitHub/NaiveBayesTextClassifier/src/cleanup_scripts:$PATH


cat $* \
    | tr -d "\r" \
    | sed '1,/^[\s\S]*[*][*][*] START/d' \
    | grep -v '^[ -\r]*$' \
    | grep -v '^\s*$' \
    | precleanup.sed \
    | upper_to_lower.bash \

