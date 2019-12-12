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
               std::map<std::string, std::vector<string> > inputPerGateMapGiven,
               std::map<std::string, std::vector<int> > inputsMapGiven,
               std::map<std::string, std::vector<int> > outputMapGiven,
               std::map<std::string, int> adjancencyMapGiven,
               std::map<std::string, std::string> nameTypeMapGiven,
               std::vector<std::string> gateNameVectorGiven,
               int gateNumberGiven, int inputNumberGiven,
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
    gateNameVector   = gateNameVectorGiven;

    GateExtractor();
    DFS(); // Finds the depth of the given circuit and classes the gates in order of reach where 0 means inputs and max means outputs
    cout << "\n------ Simulation Results and Inputs Per Gate ------ " << endl;
    for (int i = 0; i < simulationSize; i++){
        Simulation(i);
    }
}
graphs::~graphs() {
    cout << "\n------ Simulation Vectors and Results ------" << endl;
    int depth = *std::max_element(waveRankVector.begin(), waveRankVector.end());
    cout << "\nCircuit depth : " << depth << endl;
    cout << "\nCircuit input vectors per input : " << endl;
    auto it = inputsMap.begin();
    while (it != inputsMap.end()){
       cout<< it->first << " " << flush;
       for (int i = 0; i < it->second.size(); i++ ){
           if (i != it->second.size()-1) {
               cout << it->second[i] << flush;
           } else {
               cout << " "<< it->second[i] << endl;
           }
       }
       it++;
    }
    cout << "\nCircuit output vectors per output : " << endl;
    auto itt = outputsMap.begin();
    while (itt != outputsMap.end()){
        cout<< itt->first << " " << flush;
        for (int i = 0; i < itt->second.size(); i++ ){
            if (i != itt->second.size()-1) {
                cout << itt->second[i] << flush;
            } else {
                cout << " "<< itt->second[i] << endl;
            }
        }
        itt++;
    }
};
void graphs::DFS() {
    cout << "DFS begins." << endl;
    bool rangeControl = false;
    while(rangeControl == false) {
        //auto it = gatesMap.begin();
        int it = 0;
        //cout << gateNameVector[0] << endl;
        auto itControl = adjancencyMap.begin();
        while (it < gateNumber) {
            if (gatesMap[gateNameVector[it]]->waveRank == 0 && entryLevelGateVerifier(gatesMap[gateNameVector[it]]->inputNames)) {
                gatesMap[gateNameVector[it]]->waveRank = 1;
                adjancencyMap[gateNameVector[it]] = 1;
                //cout << adjancencyMap[gateNameVector[it]] << endl;
                waveRankVector.push_back(1);
                graphCheckMap.insert(std::pair<std::string, bool>(gateNameVector[it],false));//Graph creation
            } else if(gatesMap[gateNameVector[it]]->waveRank == 0){
                gatesMap[gateNameVector[it]]->waveRank = postGateVerifier(gatesMap[gateNameVector[it]]->inputNames, gatesMap[gateNameVector[it]]->waveRank);
                adjancencyMap[gateNameVector[it]] = gatesMap[gateNameVector[it]]->waveRank;
                //cout << adjancencyMap[gateNameVector[it]] << endl;
                waveRankVector.push_back(gatesMap[gateNameVector[it]]->waveRank);
                if (gatesMap[gateNameVector[it]]->waveRank != 0){ //Graph creation
                    graphCheckMap.insert(std::pair<std::string, bool>(gateNameVector[it],false));//Graph creation
                }
            }
            it++;
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
    cout << "DFS is done." << endl;
}
void graphs::GateExtractor() {
    auto it = nameTypeMap.begin(); // Map iterator declarations
    while (it != nameTypeMap.end()){ // Initializes the class map that stores the gates
        gatesMap.insert(std::make_pair(it->first, new gateInfo(it->first, it->second,inputPerGateMap[it->first],outputPerGateMap[it->first])));
        //cout<< it->first << " is created" << " type: " << it->second << endl;
        it++;
    }
}
void graphs::Simulation(int simulationTurnToken) {
    auto gateNumber = graphCheckMap.begin(); // iterator generation
    // cout << "\n- Simulation :  " << simulationTurnToken+1 << "\n" << endl;
    while ( gateNumber != graphCheckMap.end()){ // until we reach the end of the map
        if (gatesMap[gateNumber->first]->waveRank == 1 && gateNumber->second == false){ //first wave: wave rank 1
        std::vector<int> inputVector(gatesMap[gateNumber->first]->inputSize,0); // initializing the input vector
         // iterator for the input vector
        for (int i = 0; i<gatesMap[gateNumber->first]->inputNames.size(); i++){
            inputVector[i] = inputsMap[gatesMap[gateNumber->first]->inputNames[i]][simulationTurnToken];
        }
        //auto inputIt = gatesMap[gateNumber->first]->inputNames.begin(); // iterator creation for gates map
        //while(inputIt != gatesMap[gateNumber->first]->inputNames.end()){// appending the input vector
        //    inputVector[i] = inputsMap[inputIt][simulationTurnToken];
        //    inputIt++;
        //    i++;
        //}
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
            cout << "ERROR: DFS Re-visits a node, please check your gate names. Line 104 of graphs.cpp" << endl;
            terminate();
        }
        gateNumber->second = true;
        gateNumber++;
    }
    //cout << "Simulation is done!" << endl;
    auto reit = graphCheckMap.begin();
    while(reit != graphCheckMap.end()){
        graphCheckMap[reit->first] = false;
        reit++;
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
            auto itOut = outputPerGateMap.begin();
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