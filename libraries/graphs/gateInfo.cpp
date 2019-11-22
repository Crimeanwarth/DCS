//
// Created by Deniz Tohumcu on 21/11/2019.
//

#include "gateInfo.h"
#include <iostream>
#include <vector>
#include <string>

gateInfo::gateInfo(  std::string nameGiven,
                     std::string typeGiven,
                     std::vector<std::string> inputNamesGiven,
                     std::string outputNameGiven) {

    name        = nameGiven;
    type        = typeGiven;
    inputNames  = inputNamesGiven;
    outputName  = outputNameGiven;
    //inputValues = inputValuesGiven;
    inputSize   = inputNamesGiven.size();
}