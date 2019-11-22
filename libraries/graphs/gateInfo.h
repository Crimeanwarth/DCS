//
// Created by Deniz Tohumcu on 21/11/2019.
//

#ifndef TEST_GATEINFO_H
#define TEST_GATEINFO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>


class gateInfo{
public:
    int waveRank = 0;
    int inputSize;
    int output;
    std::string name;
    std::string type;
    std::vector<std::string> inputNames;
    std::string outputName;
    std::map<std::string, std::vector<int>> inputValues;
    std::vector<int> outputValues;
    gateInfo( std::string nameGiven,
              std::string typeGiven,
              std::vector<std::string> inputNamesGiven,
              std::string outputNameGiven);
};


#endif //TEST_GATEINFO_H
