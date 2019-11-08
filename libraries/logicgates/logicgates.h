//
// Created by Deniz Tohumcu on 05/11/2019.
//

#ifndef TEST_LOGICGATES_H
#define TEST_LOGICGATES_H

#include <iostream>
#include <vector>
#include <string>

class logicgates {
public:
    // Variable declaration
    std::vector<int> inputs;
    int inputSize;
    int output;
    std::string name;
    std::string type;

    // Constructor
    logicgates(int inputSizeGiven, std::string nameGiven, std::string typeGiven, std::vector<int> inputsGiven);
    ~logicgates();
    // Methods
    void outputCalculator();
};
#endif //LOGICGATES_H
