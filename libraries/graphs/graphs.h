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
#include "gateInfo.h"


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
    std::map<std::string, std::vector<string> > inputPerGateMap;
    std::map<std::string, std::vector<int> > inputsMap;
    std::map<std::string, std::vector<int> > outputsMap;
    std::map<std::string, int> adjancencyMap;
    std::map<std::string, bool> graphCheckMap;
    std::map<std::string, std::string> nameTypeMap;
    std::map<std::string, gateInfo*> gatesMap;
    //std::map<std::string, std::map< std::string,std::map< std::vector<std::string>, std::map<std::string, std::map< int,std::vector<int>>>>>> graph;// name::type::inputsName::outputName::inputSize::inputs
    int gateNumber;
    int inputNumber;
    int outputNumber;
    int simulationSize;
    // Constructor
    graphs( std::map<std::string, std::string> outputPerGateMapGiven,
            std::map<std::string, std::vector<string> > inputPerGateMapGiven,
            std::map<std::string,std::vector<int> > inputsMapGiven,
            std::map<std::string, std::vector<int> > outputMapGiven,
            std::map<std::string, int> adjancencyMapGiven,
            std::map<std::string,std::string> nameTypeMapGiven,
            int gateNumberGiven, int inputNumberGiven, int outputNumberGiven, int simulationSizeGiven);
    ~graphs();
    // Methods declaration
    void DFS ();
    void Simulation (int simulationTurnToken);
    void GateExtractor ();
    bool entryLevelGateVerifier(std::vector<std::string> gateInputNames);
    int postGateVerifier(std::vector<std::string> gateInputNames, int gateWaveRank );
};

#endif //DCS_GRAPHS_H
