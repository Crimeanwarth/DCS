#include <iostream>
#include "./libraries/parser/parser.h"
#include "./libraries/graphs/graphs.h"
using namespace std;

int main(int argc, const char * argv[]) {
    parser parsed(argc, (char *) argv);
    graphs simulation(parsed.outputPerGateMapGiven,parsed.inputPerGateMapGiven,parsed.inputsMapGiven,parsed.outputMapGiven,parsed.adjancencyMapGiven,parsed.nameTypeMapGiven,parsed.gateNumberGiven,parsed.inputNumberGiven,parsed.outputNumberGiven,parsed.simulationSizeGiven);
    return 0;
}

//TODO1: Better organizing the log functions and gather them in to log.h
//TODO2: Changing the way (optimizing) the input vectors handling in graphs.h and parser.h
//TODO3: Optimize the code for scalability
//TODO4: Make more modular functions