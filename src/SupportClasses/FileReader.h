//
// Created by 1024 on 24/04/2022.
//

#ifndef CPP_EKSAMEN3_FILEREADER_H
#define CPP_EKSAMEN3_FILEREADER_H


#include <string>
#include <vector>
#include <memory>
#include "../GameObjects/GameObject.h"

class FileReader {

public:
    static void addHighscore(int score);

   static std::vector<std::string> readLines(const char *path);

};


#endif //CPP_EKSAMEN3_FILEREADER_H
