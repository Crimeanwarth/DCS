//
// Created by Deniz Tohumcu on 07/11/2019.
//

#include "logicgates.h"
#include "logicgates_test.h"
#include <iostream>
//#include <vector>
#include <string>
using namespace std;

// Constructors
logicgates_test::logicgates_test(){};
logicgates_test::~logicgates_test(){};

// Test functions
void logicgates_test::constructor_test(){
        logicgates_test test;
        logicgates gates(test.inputSize,test.name,test.type,test.inputs);

        if (gates.inputSize == test.inputSize){
            cout << "\033[1;32m Test inputSize is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test inputSize is FAIL! \033[0m\n" << endl;
        }

        if (gates.name == test.name){
            cout << "\033[1;32m Test gateName is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test gateName is FAIL! \033[0m\n" << endl;
        }

        if (gates.type == test.type){
            cout << "\033[1;32m Test inputSize is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test inputSize is FAIL! \033[0m\n" << endl;
        }

        if (gates.inputs == test.inputs){
            cout << "\033[1;32m Test inputs is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test inputs is FAIL! \033[0m\n" << endl;
        }

       if (gates.output == 0){
            cout << "\033[1;32m Test output is PASS \033[0m\n" << endl;
       } else {
            cout << "\033[1;31m Test output is FAIL! \033[0m\n" << endl;
       }
    }


