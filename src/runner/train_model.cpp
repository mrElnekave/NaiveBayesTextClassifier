/*
main to handle these
train_model -Author=twain
writes to twain_counts.txt
and twain_vocab.txt
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> get_word_counts(std::string file_name, int& total_number_of_words);
void write_to_file(std::string file_name_counts, std::string file_name_vocab, const std::unordered_map<std::string, int>& hash_table_of_all_words, int total_number_of_words);

int main(int argc, char** argv) {
    std::string author = argv[1];
    author = author.substr(8, author.size());

    std::cout << "Training model for " << author << "..." << std::endl;

    std::string file_name = "../../data/Authors/" + author;
    int total_number_of_words;
    const std::unordered_map<std::string, int> Author_map = get_word_counts(file_name, total_number_of_words);

    // write to file
    std::string file_name_counts = "./Models/Counts/" + author;
    std::string file_name_vocab = "./Models/Vocab/" + author;
    write_to_file(file_name_counts, file_name_vocab, Author_map, total_number_of_words);
}

std::unordered_map<std::string, int> get_word_counts(std::string file_name, int& total_number_of_words) {
    std::unordered_map<std::string, int> hash_table_of_all_words;
    std::string word;
    std::ifstream myfile;
    total_number_of_words = 0;
    myfile.open(file_name, std::ofstream::out | std::ofstream::trunc);

    if (myfile.fail())
        std::cout << "File could not open " + file_name + ". GWC" << std::endl;

    while (!myfile.eof()) {
        myfile >> word;

        if (hash_table_of_all_words.find(word) == hash_table_of_all_words.end()) {
            hash_table_of_all_words[word] = 1;
        } else {
            hash_table_of_all_words[word]++;
        }
        total_number_of_words++;
    }
    myfile.close();
    return hash_table_of_all_words;
}

void write_to_file(std::string file_name_counts, std::string file_name_vocab, const std::unordered_map<std::string, int>& hash_table_of_all_words, int total_number_of_words) {
    std::ofstream myfile;
    std::ofstream myfile2;
    myfile.open(file_name_counts, std::ofstream::out | std::ofstream::trunc);  
    myfile2.open(file_name_vocab, std::ofstream::out | std::ofstream::trunc);  
    
    if (myfile.fail() | myfile2.fail())
        std::cout << "File could not open. WTF" << std::endl;

    myfile << total_number_of_words << std::endl;

    for (auto& x : hash_table_of_all_words) {
        myfile << x.first << " " << x.second << std::endl;
        myfile2 << x.first << std::endl;
    }
    myfile.close();
}

// probabilties -> logarithmic probablities.
// maps probablities, 0-1 => -inf-0 using ln function
// closer a number is to 0, the more probable it is.