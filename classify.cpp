
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

struct Author_Probability {
    std::string author;
    double probability;
};

Author_Probability random_classify(std::string input);
Author_Probability frequency_classify(std::string input);
void frequency_trainer(std::string* input, size_t size);
std::string* read_file(std::string path);

/**
 * flags: -train <author1> <author2> ... <authorN>
 *       -model=random input.txt
 *      -model=frequency input.txt
 */
int main(int argc, char** argv) {
    std::string flag = argv[1];

    if (flag == "-train") {
    } else if (flag == "model=random") {
    } else if (flag == "model=frequency") {
    }

    return 0;
}

std::string* read_file(std::string path) {
    // read a file and return its contents as a string
    std::stringstream output;

    std::ifstream infile(path);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);

        output << line << std::endl;
    }

    return new std::string(output.str());
}

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
    return;
}