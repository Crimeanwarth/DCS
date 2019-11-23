//
// Created by Deniz Tohumcu on 07/11/2019.
//

#ifndef TEST_LOGICGATES_TEST_H
#define TEST_LOGICGATES_TEST_H

#include <iostream>
#include <vector>
#include <string>

class logicgates_test {
public:
    // Test constants
    const std::string type = "AND";
    const std::string name = "G1";
    std::vector<int> inputs = {1,0};
    int output;
    const int inputSize = 2;
    const std::string outputName = "S";
    const std::vector<std::string> inputNames = {"A", "B"};
    // Constructors
    logicgates_test();
    ~logicgates_test();
    // Test functions
    void constructor_test();
};

#endif //TEST_LOGICGATES_TEST_H
