# NaiveBayesTextClassifier
-------

## Project Description

Make a text classifier, which given a text input, will tell you which author most likely wrote it.


------


Assumption: All of each author's works will be in one input file (MarkTwain.txt)

`./classify -train author1.txt ... authorn.txt`


This would create an internal model, that could classify each of the n authors, given an input.

For example:
Our "internal model" could be n files, with data distilled from the n inputs of authors.


----------------------
Running the model:

`./classify input.txt`

> Print out the score of authors greatest to least.

Ex:

> Mark twain : 900

> Snow white : 200


Using another model:

`./classify -model=random input.txt`
`./classify -model=statistical input.txt`


Goals:
* ./classify script taking in input
* Build a model that looks at relative counts of words to distinguish authors  (% of words in text)
* Some data cleaning script (python?)
