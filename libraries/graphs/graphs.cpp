//
// Created by Deniz Tohumcu on 09/11/2019.
//

#include "graphs.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "../logicgates/logicgates.h"

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
    outputMap        = outputMapGiven;
    adjancencyMap    = adjancencyMapGiven;
    nameTypeMap      = nameTypeMapGiven;
    gateNumber       = gateNumberGiven;
    inputNumber      = inputNumberGiven;
    outputNumber     = outputNumberGiven;
    simulationSize   = simulationSizeGiven;

    GateExtractor();
    DFS(); // Finds the depth of the given circuit and classes the gates in order of reach where 0 means inputs and max means outputs
    while(simulationSize > 0){

    }
}
void graphs::DFS() {
    auto it = gatesMap.begin();
    bool rangeControl = false;
    while(rangeControl == false) {
        while (it != gatesMap.end()) {
            if (it->second.waveRank == 0 && entryLevelGateVerifier(it->second.inputNames)) {
                it->second.waveRank = 1;
                adjancencyMap[it->first] = 1;
            } else {
                it->second.waveRank = postGateVerifier(it->second.inputNames, it->second.waveRank);
                adjancencyMap[it->first] = it->second.waveRank;
            }
        }
        auto itControl = adjancencyMap.begin();
        while(itControl != adjancencyMap.end()) {
            if (itControl->second == 0) {
                break;
            } else if (++itControl == adjancencyMap.end()) {
                rangeControl == true;
            }
        }
    }
}
void graphs::GateExtractor() {
    auto it = nameTypeMap.begin(); // Map iterator declarations

    while (it != nameTypeMap.end()){ // Initializes the class map that stores the gates
        gatesMap.insert(std::make_pair(it->first, gateInfo(it->first, it->second,inputPerGateMap[it->first],outputPerGateMap[it->first])));
        it++;
    }
}
void graphs::Simulation(int simulationTurnToken) {

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
                if (gateInputNames[i] == outputPerGateMap[itOut->first] && gatesMap[itOut->first].waveRank != 0) { // 0 as rank is reserved only for circuit inputs
                    waveRankVector[i] = 1 + gatesMap[itOut->first].waveRank; //injects potential waverank
                }
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
gateInfo::gateInfo( std::string nameGiven,
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