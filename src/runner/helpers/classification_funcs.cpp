

#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>

struct Author_Probability {
    std::string author;
    double probability;
};

Author_Probability random_classify(std::string input);
Author_Probability frequency_classify(std::string input);
void frequency_trainer(std::string* input, size_t size);

Author_Probability random_classify(std::string input) {
    srand(time(NULL));

    double probability = (double)rand() / (double)RAND_MAX;

    Author_Probability output;
    output.probability = probability;
    output.author = "Mark Twain";

    return output;
}

Author_Probability frequency_classify(std::string input) {
    return Author_Probability();
}

/**
 * Has input string, which is an entire book in plain text.
 *
 * We classify the amount of each word in the book, and divide it be the total amount of words.
 * Such, we get a profile of an authors writing style.
 * Ignores all non-alphabetical characters. And new lines.
 *
 * WARNING: "" is sometimes counted as a word.
 * Example: "Yamm and Nathan are working on this project.\nWow this is so cool. Damn it works on this computer. I am repeathing this.\n\n\n\n\n\n\n Even works with many new lines."
 * @param input The input string.
 * @return The frequency of each word in the book. (Authors profile)
 * NOTE: pass in an input file stream ifstream.
 * Consider this signature std::unordered_map<std::string, int> frequency_trainer(std::ifstream& input) {
 */

// returns vocab size.
/* size_t count_words (hash& hash, std::istream& stream) {
    string word;
    while (stream >> word) {

        do the hash stuff.
}
}
// Space delimeted istream, no punctuation. Normalized words.
*/
std::unordered_map<std::string, int> frequency_trainer(const std::string& input) {
    std::unordered_map<std::string, int> hash_table_of_all_words;

    std::stringstream ss(input);
    std::string temp;
    while (getline(ss, temp, '\n')) {
        std::cout << temp << std::endl;
        std::stringstream ss2(temp);
        while (getline(ss2, temp, ' ')) {
            std::cout << temp << std::endl;
            for (size_t i = 0; i < temp.length(); i++) {
                if (!isalpha(temp[i])) {
                    temp.erase(i, 1);
                }
            }
            if (hash_table_of_all_words.find(temp) == hash_table_of_all_words.end()) {
                hash_table_of_all_words[temp] = 1;
            } else {
                hash_table_of_all_words[temp]++;
            }
        }
    }

    return hash_table_of_all_words;
}

/*
Mary had a little lamb\n
and her feet where white as snow

getline(ss, temp, '\n');
getline(ss, temp, ' ');

regex?
trim commands?


*/