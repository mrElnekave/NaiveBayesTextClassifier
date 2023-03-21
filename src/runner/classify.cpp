/*

Train the model:

`./classify -train <author1> <author2> ... <authorN>`

Running the model:

`./classify -model=random <input>`
`./classify -model=statistical <input>`
*/

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "helpers/classification_funcs.cpp"

std::string read_file(std::string path);

int train_main(int argc, char* argv[]);
int random_main(int argc, char* argv[]);
int frequency_main(int argc, char* argv[]);

int classify_help() {
    std::cout << "Usage: classify [options] <input>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -train <dir_to_authors>" << std::endl;
    std::cout << "  -model=random <input>" << std::endl;
    std::cout << "  -model=frequency <input>" << std::endl;
    return 0;
}

/**
 * flags: -train <dir_to_authors>
 *        -model=random input.txt
 *        -model=frequency input.txt
 */
int main(int argc, char** argv) {
    if (argc < 3) return classify_help();

    std::string flag = argv[1];

    if (flag == "-train") {
        char command[24 + strlen(argv[2])] = "/bin/bash ./train.bash ";
        char author_name[strlen(argv[2])];
        strcpy(author_name, argv[2]);
        std::strcat(command, author_name);
        std::system(command);
        return 0;
    } else if (flag == "-model=random")
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
    std::string* authors = new std::string[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        authors[i] = argv[i + 1];
    }

    std::string* files = new std::string[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        files[i] = "data/" + authors[i] + ".txt";
    }

    std::string* contents = new std::string[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        contents[i] = read_file(files[i]);
    }

    // TODO: Train the model. using the train_model.cpp file.

    return 0;
}

/**
 * The runner for the random model.
 * @param argc: The number of arguments without the program name.
 * @param argv: The arguments without the program name.
 */
int random_main(int argc, char* argv[]) {
    if (argc < 2) return classify_help();

    std::string input = read_file(argv[1]);

    Author_Probability output = random_classify(input);

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