//
// Created by Deniz Tohumcu on 21/11/2019.
//

#ifndef TEST_GRAPHS_TEST_H
#define TEST_GRAPHS_TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "graphs.h"

class graphs_test {
public:
    const std::map<std::string, std::string> outputPerGateMap_test = {
            {"G1","a"},
            {"G2","b"},
            {"G3","c"},
            {"G4","S1"}
    };
    const std::map<std::string, std::vector<string>> inputPerGateMap_test = {
            {"G1", {"E1","E2"}},
            {"G2", {"E4"}},
            {"G3", {"b"}},
            {"G4", {"a","E3","c"}}
    };
    std::map<std::string, std::vector<int>> inputsMap_test = {
            {"E1", {0,1}},
            {"E2", {0,1}},
            {"E3", {0,0}},
            {"E4", {0,0}}
    };
    std::map<std::string, std::vector<int>> outputsMap_test = {
            {"a", {0,0}},
            {"b", {0,0}},
            {"c", {0,0}},
            {"S1", {0,0}}
    };
    std::map<std::string, int> adjancencyMap_test = {
            {"G1", 0},
            {"G2", 0},
            {"G3", 0},
            {"G4", 0}
    };
    /*std::map<std::string, bool> graphCheckMap_test = {
            {"G1", false},
            {"G2", false},
            {"G3", false},
            {"G4", false}
    };*/
    std::map<std::string, std::string> nameTypeMap_test = {
            {"G1", "AND"},
            {"G2", "INV"},
            {"G3", "INV"},
            {"G4", "OR"}
    };
    //std::map<std::string, std::map< std::string,std::map< std::vector<std::string>, std::map<std::string, std::map< int,std::vector<int>>>>>> graph;// name::type::inputsName::outputName::inputSize::inputs
    int gateNumber_test = 4;
    int inputNumber_test = 4;
    int outputNumber_test = 1;
    int simulationSize_test = 2;

    graphs_test();
    ~graphs_test();

    void DFS_test();
    void Simulation_test(int simulationTurnToken);
    void GateExtractor_test();
    bool entryLevelGateVerifier_test(std::vector<std::string> gateInputNames);
    int postGateVerifier_test(std::vector<std::string> gateInputNames, int gateWaveRank );
};


#endif //TEST_GRAPHS_TEST_H
