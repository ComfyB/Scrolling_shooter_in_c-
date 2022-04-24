//
// Created by Christoffer Lehre on 24/04/2022.
//

#include <fstream>
#include <iostream>
#include "FileReader.h"


std::vector<std::string> FileReader::readLines(const char *path) {
    std::string tmp;
    std::vector<std::string> tmpvector;
    std::ifstream file;
    file.open(path, std::ios::in);
    while (std::getline(file, tmp)) {
        tmpvector.emplace_back(tmp);
    }
    file.close();
    return tmpvector;
}

void FileReader::writeHighscore(int score) {
    u_long hslength = 0;
    std::vector<std::string> tmp = FileReader::readLines("../hs.csv");
    std::vector<int> tmpArray;

    for (const auto &s: tmp) {
        std::cout << s << std::endl;
        tmpArray.emplace_back(std::stoi(s));
    }
    tmpArray.emplace_back(score);
    std::sort(tmpArray.begin(), tmpArray.end(), std::greater<>());
    std::fstream file;
    file.open("../hs.csv");
    if (tmpArray.size() > 10) {
        hslength = 10;
    } else {
        hslength = tmpArray.size();
    }
    for (int i = 0; i < hslength; i++) {
        if (i == 9) {
            if (tmpArray.at(i))file << tmpArray.at(i);
            else
                file << "0\n";
            break;
        }
        if (tmpArray.at(i)) file << tmpArray.at(i) << '\n';
        else
            file << "0\n";
    }
    file.close();
}

std::shared_ptr<GameObject> FileReader::parseObject(std::vector<std::string> csvLines) {
    for (auto s: csvLines) {

    }
    return std::shared_ptr<GameObject>();
}
