

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

void frequency_trainer(std::string* input, size_t size) {
    std::unordered_map<std::string, int> hash_table_of_all_words;
    while (input != nullptr) {
        bool next_char_is_whitespace = false;
        size_t i = 0;
        while (!next_char_is_whitespace && input->at(i) != std::string::npos) {
            if (input->at(i) == ' ' || input->at(i) == '\n') {
                next_char_is_whitespace = true;
                break;
            }
            i++;
        }
        std::string current_word = input->substr(0, i);
        hash_table_of_all_words[current_word]++;
    }
}