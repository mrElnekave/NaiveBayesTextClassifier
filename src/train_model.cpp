/*
main to handle these
train_model -Author=twain
writes to twain_counts.txt
and twain_vocab.txt
*/

#include <fstream>
#include <iostream>
#include <string>

// make man

int main(int argc, char** argv) {
    std::string author = argv[1];
    size_t index = 8;
    author = author.substr(index, author.size() - index);

    // uses cin stream to get each word
    // while (cin > word)
    // train the models, and write to correct files

    // write all of cin to text file
    std::ofstream myfile;
    myfile.open("temp/" + author + ".txt");

    std::string word;
    while (std::cin >> word) {
        myfile << word << " ";
    }
}

// probabilties -> logarithmic probablities.
// maps probablities, 0-1 => -inf-0 using ln function
// closer a number is to 0, the more probable it is.