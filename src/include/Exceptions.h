#ifndef WORDLIST_EXCEPTIONS_H
#define WORDLIST_EXCEPTIONS_H

#include <stdexcept>
#include <cstring>

class OptionIncompatibilityException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Option incompatibility";
    }
};

class MissingFunctionalOptionException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Missing functional option -n, -w or -c";
    }
};

class OptionUsageException: public std::exception {
private:
    char message[100] = {'\0'};

public:
    explicit OptionUsageException(char* option) {
        strcpy(message, "Option usage error : ");
        strcat(message, option);
        strcat(message, " should be followed by a letter");
    }

    const char *what() const noexcept override {
        return message;
    }
};

class UnknownCommandException: public std::exception {
private:
    char message[100] = {'\0'};

public:
    explicit UnknownCommandException(char* command) {
        int l = (int) strlen(command);
        strcpy(message, "Unknown command : ");
        if (l > 50) {
            strncat(message, command, 40);
            strcat(message, "...");
        } else {
            strcat(message, command);
        }
    }

    const char *what() const noexcept override {
        return message;
    }
};

class BadOptionException: public std::exception {
private:
    char message[100] = {'\0'};

public:
    explicit BadOptionException(char* option) {
        int l = (int) strlen(option);
        strcpy(message, "Bad option : ");
        if (l > 50) {
            strncat(message, option, 40);
            strcat(message, "...");
        } else {
            strcat(message, option);
        }
    }

    const char *what() const noexcept override {
        return message;
    }
};

class FileOpenException: public std::exception {
private:
    char message[100] = {'\0'};

public:
    explicit FileOpenException(const char* filename) {
        int l = (int) strlen(filename);
        strcpy(message, "Cannot open file : ");
        if (l > 50) {
            strncat(message, filename, 40);
            strcat(message, "...");
        } else {
            strcat(message, filename);
        }
    }

    const char *what() const noexcept override {
        return message;
    }
};

class NoResultException: public std::exception {
    const char *what() const noexcept override {
        return "No satisfactory word chain";
    }
};

class NoInputFileException: public std::exception {
    const char *what() const noexcept override {
        return "Input file should be given";
    }
};

#endif //WORDLIST_EXCEPTIONS_H