# NaiveBayesTextClassifier
-------

## Project Description

Make a text classifier, which given a text input, will tell you wich author most likely wrote it.


------


Assumption: All of each author's works will be in one input file (MarkTwain.txt)

Train the model:

`./classify -train <author1> <author2> ... <authorN>`

This would create an internal model, that could classify each of the n authors, given an input.

For example:
Our "internal model" could be n files, with data distilled from the n inputs of authors.


----------------------

Running the model:

`./classify -model=random <input>`
`./classify -model=statistical <input>`

> Print out the score of authors greatest to least.

Ex:

> Mark twain : 900

> Snow white : 200


Goals:
* ./classify script taking in input
* Build a model that looks at relative counts of words to distinguish authors  (% of words in text)
* Some data cleaning script (python?)
