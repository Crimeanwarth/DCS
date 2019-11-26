#include <iostream>
#include "./libraries/parser/parser.h"
#include "./libraries/graphs/graphs.h"
using namespace std;

int main(int argc, const char * argv[]) {
    parser parsed(argc, (char *) argv);
    graphs simulation(parsed.outputPerGateMapGiven,parsed.inputPerGateMapGiven,parsed.inputsMapGiven,parsed.outputMapGiven,parsed.adjancencyMapGiven,parsed.nameTypeMapGiven,parsed.gateNumberGiven,parsed.inputNumberGiven,parsed.outputNumberGiven,parsed.simulationSizeGiven);
    return 0;
}