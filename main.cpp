#include <iostream>
#include "./libraries/logicgates/logicgates.h"
#include "./libraries/logicgates/logicgates_test.h"
//#include "./libraries/graphs/graphs.h"
//#include "./libraries/graphs/graphs_test.h"
using namespace std;

int main() {
    //graphs_test test;
    logicgates_test test;
    logicgates gate(test.inputSize,test.name,test.type,test.inputs);
    return 0;
}