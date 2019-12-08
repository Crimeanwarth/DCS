#include <iostream>
#include "./libraries/parser/parser.h"
#include "./libraries/graphs/graphs.h"
using namespace std;

int main(/*int argc, const char * argv[]*/) {
    int argc = 5;
    const char * argv[] = {"DCS", "-circuit", "/Users/deniztohumcu/Desktop/DCS/c432.txt", "-inputs", "/Users/deniztohumcu/Desktop/DCS/c432Inputs.txt"};
    parser parsed(argc, argv);
    cout << "Digital Circuit Simulator - V1.0 - 2019" << endl;
    cout << "Montpellier University - Master EEA/SEI\n"<< endl;
    graphs simulation(parsed.outputPerGateMapGiven,parsed.inputPerGateMapGiven,parsed.inputsMapGiven,parsed.outputMapGiven,parsed.adjancencyMapGiven,parsed.nameTypeMapGiven,parsed.gateNumberGiven,parsed.inputNumberGiven,parsed.outputNumberGiven,parsed.simulationSizeGiven);
    return 0;
}

//TODO: #1 Better organizing the log functions and gather them in to log.h
//TODO: #2 Changing the way (optimizing) the input vectors handling in graphs.h and parser.h
//TODO: #3 Optimize the code for scalability
//TODO: #4 Make more modular functions
//TODO: #5 Timestamped file names