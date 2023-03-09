

#include <filesystem>
#include <fstream>
#include <random>
#include <string>

struct Author_Probability {
    std::string author;
    double probability;
};

Author_Probability random_classify(std::string input, std::string* authors);
Author_Probability frequency_classify(std::string input);
void frequency_trainer(std::string* input, size_t size);

Author_Probability random_classify(std::string input, std::string* authors) {
    srand(time(NULL));
    double probability = (double)rand() / (double)RAND_MAX;

    Author_Probability output;
    output.probability = probability;

    output.author = "twain";

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
 */
std::unordered_map<std::string, int> frequency_trainer(const std::string& input) {
    std::unordered_map<std::string, int> hash_table_of_all_words;

    std::stringstream ss_current_line(input);
    std::string temp;
    while (getline(ss_current_line, temp, '\n')) {
        std::cout << temp << std::endl;
        std::stringstream ss_current_word(temp);
        while (getline(ss_current_word, temp, ' ')) {
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