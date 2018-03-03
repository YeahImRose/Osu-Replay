#include "Utils.h"

std::vector<std::string> Split(std::string str, const char* delim)
{
    std::vector<std::string> tokens;

    char *token = new char[strlen(str.c_str()) + 1];
    char *cstr = new char[strlen(str.c_str()) + 1];

    try {
        strcpy(cstr, str.c_str());
        token = strtok(cstr, delim);
        while (token != NULL)
        {
            tokens.push_back(std::string(token));
            token = strtok(NULL, delim);
        }
    }
    catch (...) {
        delete[] token;
        delete[] cstr;
        return tokens;
    }
    delete[] token;
    delete[] cstr;
    return tokens;
}