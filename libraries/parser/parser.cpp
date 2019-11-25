//
// Created by Deniz Tohumcu on 23/11/2019.
//

#include <fstream>
#include "parser.h"

parser::parser(std::string circuitFileNameGive, std::string inputFileNameGiven) {
    circuitFileName = circuitFileNameGive;
    inputFileName   = inputFileNameGiven;

    CircuitFileParser();
    InputFileParser();
}
parser::~parser() {

}

void parser::CircuitFileParser() {
    std::ifstream inputFileStream(circuitFileName);
    int count;
    inputFileStream>>count;
    int i = 0;
    while(i < count){
        std::getline(inputFileStream, line,';');
        std::istringstream lineStream(line);
        if (line != ""){
          if (i == 0){ // INPUT case
            while (std::getline(lineStream, circuitInputName, ' ' )){
                if (circuitInputName != "INPUT" || circuitInputName != " "){
                    circuitInputNameVector.push_back(circuitInputName);
                }
            }
            i++;
          }  else if (i == 1){ // OUTPUT case
            while (std::getline(lineStream,circuitOutputName, ' ')){
                if (circuitOutputName != "OUTPUT" || circuitOutputName != " "){
                    circuitOutputNameVector.push_back(circuitOutputName);
                }
            }
            i++;
          } else { // GATE case
            std::getline(lineStream, gateType , ' ');
            std::getline(lineStream, gateName, ' ');
            std::getline(lineStream, gateOutputName, ' ');
            while (std::getline(lineStream, gateInputName, ' ')){
                gateInputNameVector.push_back(gateInputName);
            }
            outputPerGateMapGiven.insert({gateName, gateOutputName});
            inputPerGateMapGiven.insert({gateName, gateInputNameVector});
            adjancencyMapGiven.insert({gateName,0});
            nameTypeMapGiven.insert({gateName, gateType});
            gateOutputNameVector.push_back(gateOutputName);
            i++;
          }
        }
    }
    gateNumberGiven = i - 1;
    inputNumberGiven = circuitInputNameVector.size();
    outputNumberGiven = circuitOutputName.size();
}

void parser::InputFileParser() {
    std::ifstream inputFileStream(inputFileName);
    int count;
    inputFileStream>>count;
    int i = 0;
    while (i < count){
        std::getline(inputFileStream, line,' ');
        std::istringstream lineStream(line);
        if (line != " ") {
            if (i == 0) {
                simulationSizeGiven = stoi(line);
                i++;
            } else {
                int it = 0;
                while (it < inputNumberGiven) {
                    if (it == 0) {
                        inputsMapGiven.({gateOutputNameVector[it], stoi(line)/(10^(inputNumberGiven-1-it)) });
                    }
                    it++;
                }
            }
        }
    }
}

void parser::LineAnalyser() {

}


