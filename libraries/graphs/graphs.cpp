//
// Created by Deniz Tohumcu on 09/11/2019.
//

#include "graphs.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../logicgates/logicgates.h"
#include "gateInfo.h"

graphs::graphs(std::map<std::string, std::string> outputPerGateMapGiven,
               std::map<std::string, std::vector<string>> inputPerGateMapGiven,
               std::map<std::string, std::vector<int>> inputsMapGiven,
               std::map<std::string, std::vector<int>> outputMapGiven,
               std::map<std::string, int> adjancencyMapGiven,
               std::map<std::string, std::string> nameTypeMapGiven, int gateNumberGiven, int inputNumberGiven,
               int outputNumberGiven, int simulationSizeGiven) {

    outputPerGateMap = outputPerGateMapGiven;
    inputPerGateMap  = inputPerGateMapGiven;
    inputsMap        = inputsMapGiven;
    outputsMap       = outputMapGiven;
    adjancencyMap    = adjancencyMapGiven;
    nameTypeMap      = nameTypeMapGiven;
    gateNumber       = gateNumberGiven;
    inputNumber      = inputNumberGiven;
    outputNumber     = outputNumberGiven;
    simulationSize   = simulationSizeGiven;

    //GateExtractor();
    //DFS(); // Finds the depth of the given circuit and classes the gates in order of reach where 0 means inputs and max means outputs
    //for (int i = 0; i < simulationSize; i++){
      //  Simulation(i);
    //}
}
graphs::~graphs() {};
void graphs::DFS() {
    bool rangeControl = false;
    while(rangeControl == false) {
        auto it = gatesMap.begin();
        auto itControl = adjancencyMap.begin();
        while (it != gatesMap.end()) {
            if (it->second->waveRank == 0 && entryLevelGateVerifier(it->second->inputNames)) {
                it->second->waveRank = 1;
                adjancencyMap[it->first] = 1;
                graphCheckMap.insert(std::pair<std::string, bool>(it->first,false));//Graph creation
                it++;
            } else if(it->second->waveRank == 0){
                it->second->waveRank = postGateVerifier(it->second->inputNames, it->second->waveRank);
                adjancencyMap[it->first] = it->second->waveRank;
                if (it->second->waveRank != 0){ //Graph creation
                    graphCheckMap.insert(std::pair<std::string, bool>(it->first,false));//Graph creation
                }
                it++;
            }
        }
        while(itControl != adjancencyMap.end()) {
            auto check = itControl;
            check++;
            if (itControl->second == 0){
                break;
            } else if (check == adjancencyMap.end()) {
                rangeControl = true;
            }
            itControl++;
        }
    }
}
void graphs::GateExtractor() {
    auto it = nameTypeMap.begin(); // Map iterator declarations
    while (it != nameTypeMap.end()){ // Initializes the class map that stores the gates
        gatesMap.insert(std::make_pair(it->first, new gateInfo(it->first, it->second,inputPerGateMap[it->first],outputPerGateMap[it->first])));
        it++;
    }
}
void graphs::Simulation(int simulationTurnToken) {
    auto gateNumber = graphCheckMap.begin(); // iterator generation
    while ( gateNumber != graphCheckMap.end()){ // until we reach the end of the map
        if (gatesMap[gateNumber->first]->waveRank == 1 && gateNumber->second == false){ //first wave: wave rank 1
        std::vector<int> inputVector(gatesMap[gateNumber->first]->inputSize,0); // initializing the input vector
        int i = 0; // iterator for the input vector
        auto inputIt = gatesMap[gateNumber->first]->inputValues.begin(); // iterator creation for gates map
        while(inputIt != gatesMap[gateNumber->first]->inputValues.end()){// appending the input vector
            inputVector[i] = inputIt->second[simulationTurnToken];
            inputIt++;
            i++;
        }
        logicgates actualGate(gatesMap[gateNumber->first]->inputSize,gatesMap[gateNumber->first]->name,gatesMap[gateNumber->first]->type,inputVector,gatesMap[gateNumber->first]->outputName, gatesMap[gateNumber->first]->inputNames); //calculating
        gatesMap[gateNumber->first]->outputValues.push_back(actualGate.output); //indexing result
        outputsMap[gatesMap[gateNumber->first]->outputName][simulationTurnToken] = actualGate.output;// indexing result
        } else if(gateNumber->second == false) {
            std::vector<int> inputVector(gatesMap[gateNumber->first]->inputSize,0);
            for (int i = 0; i < inputVector.size(); i++){
                if(inputsMap.find(gatesMap[gateNumber->first]->inputNames[i]) != inputsMap.end()){
                    inputVector[i] = inputsMap[gatesMap[gateNumber->first]->inputNames[i]][simulationTurnToken];
                }else if (outputsMap.find(gatesMap[gateNumber->first]->inputNames[i]) != outputsMap.end()){
                    inputVector[i] = outputsMap[gatesMap[gateNumber->first]->inputNames[i]][simulationTurnToken];
                }
            }
            logicgates actualGate(gatesMap[gateNumber->first]->inputSize,gatesMap[gateNumber->first]->name,gatesMap[gateNumber->first]->type,inputVector,gatesMap[gateNumber->first]->outputName, gatesMap[gateNumber->first]->inputNames); //calculating
            gatesMap[gateNumber->first]->outputValues.push_back(actualGate.output); //indexing result
            outputsMap[gatesMap[gateNumber->first]->outputName][simulationTurnToken] = actualGate.output;// indexing result
        } else {
            cout << "\033[1;31m ERROR: DFS Re-visits a node, please check your gate names. Line 104 of graphs.cpp \033[0m\n" << endl;
            terminate();
        }
        gateNumber->second = true;
        gateNumber++;
    }
}
bool graphs::entryLevelGateVerifier(std::vector<std::string> gateInputNames) {
    for (int i = 0; i<gateInputNames.size(); i++){
        if ( inputsMap.find(gateInputNames[i]) == inputsMap.end() ){ //if it is the end value then the inputs is not in the circuit inputs map
                return false;
        }
    }
    return true;
}
int graphs::postGateVerifier(std::vector<std::string> gateInputNames, int gateWaveRank) {
    auto itOut = outputPerGateMap.begin();
    std::vector<int> waveRankVector(gateInputNames.size(), 0);
    if (gateWaveRank == 0) {
        for (int i = 0; i < gateInputNames.size(); i++) {
            while (itOut != outputPerGateMap.end()) {
                if (gateInputNames[i] == outputPerGateMap[itOut->first] && gatesMap[itOut->first]->waveRank != 0) { // means not calculated 0 as rank is reserved only for circuit inputs
                    waveRankVector[i] = 1 + gatesMap[itOut->first]->waveRank; //injects potential waverank
                    break;
                } else if (inputsMap.find(gateInputNames[i]) != inputsMap.end()) {
                    waveRankVector[i] = 1;
                    break;
                }
                itOut++;
            }
        }
        if ( std::find(waveRankVector.begin(), waveRankVector.end(), 0) == waveRankVector.end() ){ // checks if there is no illegal (rank 0) rank in a vector
            return *std::max_element(waveRankVector.begin(),waveRankVector.end()); //returns the max value of the list according to last to arrive input
        } else {
            return 0;
        }
    } else {
        return gateWaveRank;
    }
}