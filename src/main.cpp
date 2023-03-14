#include "ArgParser.h"
#include "FileParser.h"
#include "Controller.h"
#include <iostream>

void printUsage() {
    char usage[] = "\n"
                   "Usage: \n"
                   "  Wordlist <function> <filename> [options]\n"
                   "\n"
                   "Functional Options:\n"
                   "  -n             Get the total number of word chains.\n"
                   "  -w             Get the word chain with the most words.\n"
                   "  -c             Get the word chain with the most letters.\n"
                   "\n"
                   "Additional Options:\n"
                   "  -h <head>      Specify the first letter of the chain.\n"
                   "  -t <tail>      Specify the last letter of the chain.\n"
                   "  -j <except>    Specifies a letter that cannot be the first letter of any word in the chain.\n"
                   "  -r             Allow implicit word circles.\n"
                   "\n";
    printf("%s", usage);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc == 1) printUsage();

    try {
        ArgParser argParser = ArgParser(argc, argv);
        UserOptions userOptions = argParser.getOptions();
        FileParser fileParser = FileParser(argParser.getFilename());
        char** words = fileParser.getWords();
        int len = fileParser.getWordsNum();
        Controller controller = Controller(userOptions, words, len);
        controller.run();
    } catch (std::exception &e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
        return 1;
    }
    return 0;
}
