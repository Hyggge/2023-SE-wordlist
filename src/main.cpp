#include "ArgParser.h"
#include "FileParser.h"
#include "Controller.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        ArgParser argParser = ArgParser(argc, argv);
        UserOptions userOptions = argParser.getOptions();
        FileParser fileParser = FileParser(argParser.getFilename());
        char** words = fileParser.getWords();
        int len = fileParser.getWordsNum();
        Controller controller = Controller(userOptions, words, len);
        controller.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
