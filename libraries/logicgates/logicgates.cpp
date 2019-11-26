//
// Created by Deniz Tohumcu on 05/11/2019.
//

#include "logicgates.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

    //Constructor and Destructor
    logicgates::logicgates (int inputSizeGiven,string nameGiven, string typeGiven, vector<int> inputsGiven, std::string outputNameGiven, std::vector<std::string> inputNamesGiven){
        if (inputSizeGiven == 0){
            cerr << "ERROR: Minimum input size is 1 " << endl;
            exit(-1);
        }else if (inputSizeGiven == 1){
            inputs.push_back(0); //Appending to the inputs vector
            inputSize = inputSizeGiven;
            name = nameGiven;
            type = typeGiven;
            outputName = outputNameGiven;
            inputNames = inputNamesGiven;
            if (inputs.size() == inputsGiven.size()){ //checks if the array sizes are equal in order to prevent segmentation error.
                inputs = inputsGiven;
            }else{
                cerr << "\033[1;31m ERROR: Segmentation error : your input size is not the same as the numbers of inputs that are given! \033[0m\n" << endl;
                terminate();
            }
            outputCalculator();
        }else{
            for(int i=0; i<inputSizeGiven; i++) {// Appending in to the inputs vector
                inputs.push_back(0);
            }
            inputSize = inputSizeGiven;
            name = nameGiven;
            type = typeGiven;
            outputName = outputNameGiven;
            inputNames = inputNamesGiven;
            if (inputs.size() == inputsGiven.size()){ //checks if the array sizes are equal in order to prevent segmentation error.
                inputs = inputsGiven;
            }else{
                cerr << "\033[1;31m ERROR: Segmentation error : your input size is not the same as the numbers of inputs that are given! \033[0m\n" << endl;
                terminate();
            }
            outputCalculator();
        }
    }
    logicgates::~logicgates() {
        cout << "\n\n" << endl;
        cout << "Name: " << name << " TYPE: " << type << " Input Size: " << inputSize << endl;
        for (int i = 0; i<inputSize; i++)
        {
            cout << " Input name : " << inputNames[i] << " Value : " << inputs[i] << endl;
        }
        cout << " Output name : " << outputName << " Value : " << output << endl;
        cout << "\n\n" << endl;
    }

void logicgates::outputCalculator() { // Calculates output
        if (inputSize > 1){
            if (type == "AND"){
                for (int i = 0; i<inputSize; i++ )
                {
                    if( i == 0 ) {
                        output = inputs[i] and inputs[i + 1];
                    } else {
                        output = inputs[i] and output;
                    }
                }
            } else if (type == "OR") {
                for (int i = 0; i<inputSize; i++ )
                {
                    if( i == 0 ) {
                        output = inputs[i] or inputs[i + 1];
                    } else {
                        output = inputs[i] or output;
                    }
                }
            } else if (type == "XOR") {
                for (int i = 0; i<inputSize; i++ )
                {
                    if( i == 0 ) {
                        output = inputs[i] xor inputs[i + 1];
                    } else {
                        output = inputs[i] xor output;
                    }
                }
            } else { // Error for alien gate
                cerr << "\033[1;31m ERROR: Unknown gate type! \033[0m\n" << endl;
                terminate();
            }
        } else if (inputSize == 1) {
            if (type == "INV"){
                output = !inputs[0];
            } else { // Inverters size error
                cerr << "\033[1;31m ERROR: Inverters can't have more then one input! \033[0m\n" << endl;
                terminate();
            }
        } else { // Impossible size error
            cerr << "\033[1;31m ERROR: Input size not possible! \033[0m\n" << endl;
            terminate();
        }
}