/*

Train the model:

`./classify -train <author1> <author2> ... <authorN>`

Running the model:

`./classify -model=random <input>`
`./classify -model=statistical <input>`
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "classification_funcs.cpp"

std::string read_file(std::string path);

int train_main(int argc, char* argv[]);
int random_main(int argc, char* argv[]);
int frequency_main(int argc, char* argv[]);

int classify_help() {
    std::cout << "Usage: classify [options] <input>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -train <author1> <author2> ... <authorN>" << std::endl;
    std::cout << "  -model=random <input>" << std::endl;
    std::cout << "  -model=frequency <input>" << std::endl;
    return 0;
}

/**
 * flags: -train <author1> <author2> ... <authorN>
 *        -model=random input.txt
 *        -model=frequency input.txt
 */
int main(int argc, char** argv) {
    if (argc < 3) return classify_help();

    std::string flag = argv[1];

    if (flag == "-train")
        return train_main(argc - 1, argv + 1);
    else if (flag == "-model=random")
        // return 1;
        return random_main(argc - 1, argv + 1);
    else if (flag == "-model=statistical")
        return frequency_main(argc - 1, argv + 1);

    else
        return classify_help();
}

/**
 * The runner for the training function.
 * @param argc: The number of arguments without the program name.
 * @param argv: The arguments without the program name.
 */
int train_main(int argc, char* argv[]) {
    std::string authors[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        authors[i] = argv[i + 1];
    }

    std::string files[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        files[i] = "data/" + authors[i] + ".txt";
    }

    std::string contents[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        contents[i] = read_file(files[i]);
    }

    // train(contents, argc - 1);
    auto map = frequency_trainer("Yamm and Nathan are working on this project.\nWow this is so cool. Damn it works on this computer. I am repeathing this.\n\n\n\n\n\n\n Even works with many new lines.");
    for (auto it = map.begin(); it != map.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}

/**
 * The runner for the random model.
 * @param argc: The number of arguments without the program name.
 * @param argv: The arguments without the program name.
 */
int random_main(int argc, char* argv[]) {
    std::string input = read_file(argv[1]);
    std::string authors[argc - 1];
    for (int i = 0; i < argc; i++) {
        authors[i] = argv[i];
    }
    Author_Probability output = random_classify(input, authors);

    std::cout << "Author: " << output.author << std::endl;
    std::cout << "Probability: " << output.probability << std::endl;
    return 0;
}

/**
 * The runner for the frequency model.
 * @param argc: The number of arguments without the program name.
 * @param argv: The arguments without the program name.
 */
int frequency_main(int argc, char* argv[]) {
    if (argc < 2) return classify_help();

    std::string input = read_file(argv[1]);

    Author_Probability output = frequency_classify(input);

    std::cout << "Author: " << output.author << std::endl;
    std::cout << "Probability: " << output.probability << std::endl;

    return 0;
}

/**
 * Read a file into a string.
 * @return The contents of the file.
 */
std::string read_file(std::string path) {
    std::stringstream output;

    std::ifstream infile(path);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);

        output << line << std::endl;
    }

    return output.str();
}
