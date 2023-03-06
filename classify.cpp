
#include <iostream>
#include <string>

int random_classify(std::string input);
int frequency_classify(std::string input);
void frequency_trainer(std::string* input, size_t size);
std::string* read_file(std::string path);

int main(int argc, char** argv) {
    std::cout << "amount of args " << argc << std::endl;

    for (size_t i = 0; i < argc; i++) {
        std::cout << "arg " << i << " is " << argv[i] << std::endl;
    }

    return 0;
}

std::string* read_file(std::string path) {
    return nullptr;
}

int random_classify(std::string input) {
    return 0;
}

int frequency_classify(std::string input) {
    return 0;
}

void frequency_trainer(std::string* input, size_t size) {
    return;
}