//
// Created by Deniz Tohumcu on 21/11/2019.
//

#include "graphs_test.h"
#include <iostream>
#include "graphs.h"

graphs_test::graphs_test(){
    graphs test_circuit(outputPerGateMap_test,inputPerGateMap_test,inputsMap_test,outputsMap_test,adjancencyMap_test,nameTypeMap_test,gateNumber_test,inputNumber_test,outputNumber_test,simulationSize_test);
    // GateExtractor test
    auto it = test_circuit.gatesMap.begin();
    while (it != test_circuit.gatesMap.end()){
        if (it->second->waveRank == 0) {
            cout << "\033[1;32m Test waveRank of "<< it->first <<" is! PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test waveRank of "<< it->first << "is FAIL! \033[0m\n" << endl;
        }
        if (it->second->inputNames == inputPerGateMap_test[it->first]) {
            cout << "\033[1;32m Test inputNames of "<< it->first <<" is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test inputNames of "<< it->first << "is FAIL! \033[0m\n" << endl;
        }
        if (it->second->name == it->first) {
            cout << "\033[1;32m Test name of "<< it->first <<" is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test name of "<< it->first << "is FAIL! \033[0m\n" << endl;
        }
        if (it->second->type == nameTypeMap_test[it->first]) {
            cout << "\033[1;32m Test type of "<< it->first <<" is PASS \033[0m\n" << endl;
        } else {
            cout << "\033[1;31m Test type of "<< it->first << "is FAIL! \033[0m\n" << endl;
        }
        it++;
    }

    //DFS test

    if (test_circuit.adjancencyMap["G1"] == 1) {
        cout << "\033[1;32m Test waveRank of G1 is PASS \033[0m\n" << endl;
    } else {
        cout << "\033[1;31m Test waveRank of is FAIL! \033[0m\n" << endl;
    }
    if (test_circuit.adjancencyMap["G2"] == 1) {
        cout << "\033[1;32m Test waveRank of G2 is PASS \033[0m\n" << endl;
    } else {
        cout << "\033[1;31m Test waveRank of is FAIL! \033[0m\n" << endl;
    }
    if (test_circuit.adjancencyMap["G3"] == 2) {
        cout << "\033[1;32m Test waveRank of G3 is PASS \033[0m\n" << endl;
    } else {
        cout << "\033[1;31m Test waveRank of is FAIL! \033[0m\n" << endl;
    }
    if (test_circuit.adjancencyMap["G4"] == 3) {
        cout << "\033[1;32m Test waveRank of G4 is PASS \033[0m\n" << endl;
    } else {
        cout << "\033[1;31m Test waveRank of is FAIL! \033[0m\n" << endl;
    }




}
graphs_test::~graphs_test() {};

