// Read individual words from stdin into a hash map, at the end, traverse the map and dump the total counts.
// These counts should agree with the counts produced on the command line using the filter I sent in email.
// The code should typically be no more than 10-20 lines (don't need to mess with flags and command variations yet)
// Once this is working, I'll show you how to calculate the probability of a sentence using a finite vocab
// An extension of this can be applied to generate the bigram (2nd order LM) which gives P(w2|w1) so you can
// calculate P(S) = \prod_{i = 1}^n P(w_{i-1} | w_i) or equivalently \sum_{i = 1}^n \log P(w_{i-1} | w_i)
//
// Once you can calculate the (log) probability of the corpus given each author's LM, you can make a heuristic
// decision that predicted_author = \argmax_{A \in Authors} \log P(A|Corpus)
// You can calculate P(A|C) as P(C|A) * P(A) / P(C)
// The P(C|A) = prob of the corpus given the language model for author A and
// P(C) is simply sum_{all A} P(C,A). Since this quantity is invariant across the contenders in your argmax you can
// ignore it and rewrite the eq as
//   Predicted Author = \argmax_{A \in Authors} \sum_{i = 1}^n \log P(w_{i-1} | w_i, A} * P(A)
// If you assume all authors equally likely a-priori you can ignore the prior P(A) in the argmax and simply write
// Predicted Author = \argmax_{A \in Authors} \sum_{i = 1}^n \log P(w_{i-1} | w_i, A}

// Note What's the prob of a corpus? It is simply the product of the probs of each sentence in the corpus
// What is the prob of a sent: It is simply the prod of the prod of each token (with ngram assumptions)
// Note: Ignore P(<S>) for each sent in the bigram model and assume that the first word with history is
// the first token following <S>. However </S> should have bigram context.
// 
// The unigram level coarse result will be suggestive
// The next order bigram results will be more accurate and so on.

// PS. For the bigram model, for now, you can ignore P(<S>)

// When we meet I can explain the theory of this, it's pretty straightforward (only basic stats)
// The eqns abve may look prettier if you TeXify them - Maybe try pasting into Google Docs eqn mode box.
// Will explain in as much detail as needed next time we meet.

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cout << "Hello world\n";

    return 0; ////////// 

    string word;
    while (cin >> word) {
        // stuff word in hash
        ;

        // Iterate over hash and remove all keys with count < 5, for example
        // As a side-effect, calculate (1) the vocab size # of uniq words or hash keys and (2) Total counts
        // you can verify these counts from the cmd line run I showed in the email.

        // Second iteration over hash. This time for each key, print
        // word \t frequency \t frequency/total (prob) \t ln(freq/total) \n

        // You can also start of the output with total counts in comment style e.g.
        // # Vocab size 3891
        // # Token count 497648
        // <S> \t 3890  \t  9.12E-7   \t -12323.42124 \n
        // ...
    }

    return 0;
}
