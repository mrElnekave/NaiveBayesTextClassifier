#!/usr/bin/bash

export PATH=/mnt/c/Users/Nathan/Documents/GitHub/NaiveBayesTextClassifier/NaiveBayesTextClassifier/src/cleanup_scripts:$PATH


cat $* \
    | tr -d "\r" \
    | sed '1,/^[\s\S]*[*][*][*] START/d' \
    | precleanup.sed \
    | grep -v '^[ -\r]*$' \
    | grep -v '^\s*$' \
    | upper_to_lower.bash \

