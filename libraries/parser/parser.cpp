//
// Created by Deniz Tohumcu on 23/11/2019.
//

#include <fstream>
#include "parser.h"
#include "log.h"

parser::parser(int argc, char argv[]){
    GetArg(argc, argv);
    log logger();
    CircuitFileParser();
    InputFileParser();
    Init();
}
parser::~parser() {
    std::cout << "Circuit Information" << std::endl;
    std::cout << "Input Names : " << std::endl;
    for (int i = 0; i<circuitInputNameVector.size(); i++){
        std::cout << circuitInputNameVector[i] << std::endl;
    }
    std::cout << "Output Names : " << std::endl;
    for (int i = 0; i<circuitOutputNameVector.size(); i++){
        std::cout << circuitOutputNameVector[i] << std::endl;
    }
    std::cout << "Gate Names and Types : " << std::endl;
    auto it = nameTypeMapGiven.begin();
    while(it != nameTypeMapGiven.end()){
        std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }
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
    inputFileStream >> count;
    int i = 0;
    while (i < count) {
        std::getline(inputFileStream, line, ' ');
        std::istringstream lineStream(line);
        if (line != " ") {
            if (i == 0) {
                simulationSizeGiven = stoi(line);
                i++;
            } else {
                int it = 0;
                int vec = stoi(line);
                while (it < inputNumberGiven) {
                    if (it == 0 && count == 0) {
                        inputsMapGiven.insert({gateInputNameVector[it], {vec / (10 ^ (inputNumberGiven - 1 - it))}});
                        inputValue = vec / (10 ^ (inputNumberGiven - 1 - it));
                        if (inputValue == 1) {
                            vec = vec - 10 ^ (inputNumberGiven - 1 - it);
                        } else if (inputValue != 0) {
                            std::cerr << "\033[1;31m ERROR: Non binary value is found! " << inputFileName << " : "
                                      << "line ->" << i << " \033[0m\n" << std::endl;
                            std::terminate();
                        }
                        it++;
                    } else {
                        inputsMapGiven[gateInputNameVector[it]].push_back(vec / (10 ^ (inputNumberGiven - 1 - it)));
                        inputValue = vec / (10 ^ (inputNumberGiven - 1 - it));
                        if (inputValue == 1) {
                            vec = vec - 10 ^ (inputNumberGiven - 1 - it);
                        } else if (inputValue != 0) {
                            std::cerr << "\033[1;31m ERROR: Non binary value is found! " << inputFileName << " : "
                                      << "line ->" << i << " \033[0m\n" << std::endl;
                            std::terminate();
                        }
                        it++;
                    }
                }
                i++;
            }
        }
    }
}

void parser::Init() {
    std::vector<int> outputs(simulationSizeGiven, 0);
    auto it = outputPerGateMapGiven.begin();
    while (it != outputPerGateMapGiven.end()) {
        outputMapGiven.insert({it->second, outputs});
        it++;
    }
}

void parser::GetArg(int argc, char argv[]) {
    if ( argc == 5 ){
        if (argv[1] == '-circuit' || argv [3] == '-circuit'){
            if (argv[1] == '-circuit'){
                circuitFileName = argv[2];
            } else {
                circuitFileName = argv[4];
            }
        } else {
            std::cerr << "\033[1;31m Error: Unknown type has been given! \033[0m\n" << std::endl;
            std::cerr << "Exemple : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
            std::terminate();
        } if ( argv[1] == '-inputs' || argv[3] == '-inputs'){
            if (argv[3] == '-inputs' ){
                inputFileName = argv[4];
            } else {
                inputFileName = argv[2];
            }
        } else {
            std::cerr << "\033[1;31m Error: Unknown type has been given! \033[0m\n" << std::endl;
            std::cerr << "Exemple : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
            std::terminate();
        }
    } else {
       std::cerr << "\033[1;31m Error: Not enough arguments! \033[0m\n" << std::endl;
       std::cerr << "Exemple : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
       std::terminate();
    }
}