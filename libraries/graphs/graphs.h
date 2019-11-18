//
// Created by Deniz Tohumcu on 09/11/2019.
//

#ifndef DCS_GRAPHS_H
#define DCS_GRAPHS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../logicgates/logicgates.h"

using namespace std;

class graphs {
public:
    // Variables declarations
   /* std::vector<std::string> inputsNameVector;
    std::vector<int> inputsValues; //inputs::inputs
    std::vector<std::string> outputsName;
    std::vector<int> outputsValues;//output::value
    std::vector<std::string> allNodes;
    std::vector<bool> adjancencyVector;//node::visited
    std::vector<std::string> nameVector;
    std::vector<std::string> typeVector;//name::type
   */
    std::map<std::string, std::string> outputPerGateMap;
    std::map<std::string, std::vector<string>> inputPerGateMap;
    std::map<std::string, std::vector<int>> inputsMap;
    std::map<std::string, std::vector<int>> outputMap;
    std::map<std::string, std::vector<bool>> adjancencyMap;
    std::map<std::string, std::string> nameTypeMap;
    std::map<std::string, class gateInfo> gatesMap;
    //std::map<std::string, std::map< std::string,std::map< std::vector<std::string>, std::map<std::string, std::map< int,std::vector<int>>>>>> graph;// name::type::inputsName::outputName::inputSize::inputs
    int gateNumber;
    int inputNumber;
    int outputNumber;
    int simulationSize;
    int simulationTurnToken = 0;
    // Constructor
    graphs( std::map<std::string, std::string> outputPerGateMapGiven,
            std::map<std::string, std::vector<string>> inputPerGateMapGiven,
            std::map<std::string,std::vector<int>> inputsMapGiven,
            std::map<std::string, std::vector<int>> outputMapGiven,
            std::map<std::string, std::vector<bool>> adjancencyMapGiven,
            std::map<std::string,std::string> nameTypeMapGiven,
            int gateNumberGiven, int inputNumberGiven, int outputNumberGiven, int simulationSizeGiven);
    ~graphs();
private:
    // Methods declaration
    void DFS ();
    void Simulation (int simulationTurnToken);
    void GateExtractor ();
    bool entryLevelGateVerifier(std::vector<std::string> gateInputNames);
    int postGateVerifier(std::vector<std::string> gateInputNames, std::vector<std::string> gateOutputNameVector, int gateWaveRank );

};

class gateInfo {
public:
    int waveRank = 0;
    int inputSize;
    int output;
    std::string name;
    std::string type;
    std::vector<std::string> inputNames;
    std::string outputName;
    std::map<std::string, vector<int>> inputValues;

    gateInfo( std::string nameGiven,
              std::string typeGiven,
              std::vector<std::string> inputNamesGiven,
              std::string outputNameGiven);
};
#endif //DCS_GRAPHS_H
