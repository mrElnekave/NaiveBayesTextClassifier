

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>

struct Author_Probability {
    std::string author;
    double probability;

    bool operator<(const Author_Probability& other) const {
        return probability < other.probability;
    }
    bool operator>(const Author_Probability& other) const {
        return probability > other.probability;
    }
};

Author_Probability random_classify(std::string input);
std::vector<Author_Probability> frequency_classify(std::string input);
float frequency_helper(std::unordered_map<std::string, float> map, std::ifstream& file, int total_number_of_words);
std::unordered_map<std::string, float> read_from_model_file(std::string file_name, int& total_number_of_words);
float get_probability(int count_of_word, int total_number_of_words);

Author_Probability random_classify(std::string input) {
    srand(time(NULL));

    double probability = (double)rand() / (double)RAND_MAX;

    Author_Probability output;
    output.probability = probability;
    output.author = "Mark Twain";

    return output;
}

/**
 * @brief Classify the input using the frequency model
 * Open all the files in ../Models/* and read the data of each author
 * Calculate the probablity of the author given the input
 *
 * @param file the input file to classify
 * @param path_to_models the path to the models folder
 * @return sorted vector of Author_Probability, most likely first
 */
std::vector<Author_Probability> frequency_classify(std::ifstream& file, std::string path_to_models) {
    std::vector<Author_Probability> output;

    std::filesystem::directory_iterator directory(path_to_models);

    int start_of_file = file.tellg();

    for (const auto& file_name : directory) {
        std::cout << "testing " << file_name.path().stem().string() << " model" << std::endl;
        int total_number_of_words;
        auto map = read_from_model_file(file_name.path().string(), total_number_of_words);

        file.seekg(start_of_file);
        float probability = frequency_helper(map, file, total_number_of_words);

        Author_Probability author_probability;
        author_probability.author = file_name.path().stem().string();
        author_probability.probability = probability;

        output.push_back(author_probability);
    }

    std::sort(output.begin(), output.end(), std::greater<Author_Probability>());

    return output;
}

float frequency_helper(std::unordered_map<std::string, float> map, std::ifstream& file, int total_number_of_words) {
    float probability = 1.0;
    std::string word;
    while (!file.eof()) {
        file >> word;
        probability *= map[word] + 1.0 / (float)total_number_of_words;
    }
    return probability;
}

std::unordered_map<std::string, float> read_from_model_file(std::string file_name, int& total_number_of_words) {
    std::ifstream myfile;
    myfile.open(file_name, std::ifstream::in);  // change this directory to the clean data folder once we have it

    if (myfile.fail())
        std::cout << "File could not open." << std::endl;

    std::unordered_map<std::string, float> hash_table_of_all_words;
    std::string word;
    int count_of_word;
    myfile >> total_number_of_words;

    while (!myfile.eof()) {
        myfile >> word;
        myfile >> count_of_word;

        hash_table_of_all_words[word] = get_probability(count_of_word, total_number_of_words);
    }

    myfile.close();

    return hash_table_of_all_words;
}

/**
 * @brief Get the probability word, given the total number of words
 * In the future use ln(probability) to avoid underflow
 *
 * @param count_of_word
 * @param total_number_of_words
 * @return float
 */
float get_probability(int count_of_word, int total_number_of_words) {
    return (float)count_of_word / (float)total_number_of_words;
    // use ln
    // return log((float)count_of_word / (float)total_number_of_words);
}