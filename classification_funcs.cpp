

#include <fstream>
#include <random>
#include <string>

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
 * @param input The input string.
 * @return The frequency of each word in the book. (Authors profile)
 */
std::unordered_map<std::string, int> frequency_trainer(const std::string& input) {
    std::unordered_map<std::string, int> hash_table_of_all_words;
    while (input != "") {
        bool next_char_is_whitespace = false;
        size_t i = 0;
        while (!next_char_is_whitespace && input.at(i) != std::string::npos) {
            if (input.at(i) == ' ' || input.at(i) == '\n') {
                next_char_is_whitespace = true;
                break;
            }
            i++;
        }
        std::string current_word = input.substr(0, i);  // Will cut off substring, and update input string.
        hash_table_of_all_words[current_word]++;
    }
}

void call() {
    auto temp = frequency_trainer("Hello, my name is Mark Twain. I am a writer.");
}