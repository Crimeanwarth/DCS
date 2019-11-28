//
// Created by Deniz Tohumcu on 23/11/2019.
//

#include "parser.h"
using namespace std;

parser::parser(int argc, const char * argv[]){
    GetArg(argc, argv);
    std::freopen( "output.txt","w",stdout);
    std::freopen( "error.txt", "w",stderr);
    CircuitFileParser();
    InputFileParser();
    Init();
};
parser::~parser() {
    std::cout << "\n------ Circuit Information ------\n" << std::endl;
    std::cout << "Input Names : " << std::flush;
    for (int i = 0; i<circuitInputNameVector.size(); i++){
        if (i == 0){
            std::cout << circuitInputNameVector[i] << std::flush;
        } else {
            std::cout<< " " << circuitInputNameVector[i] << std::flush;
        }
    }
    std::cout << "\n\nOutput Names : " << std::flush;
    for (int i = 0; i<circuitOutputNameVector.size(); i++){
        if (i == 0){
            std::cout << circuitOutputNameVector[i] << std::flush;
        } else {
            std::cout << " " << circuitOutputNameVector[i] << std::flush;

        }
    }
    std::cout << "\n\nGate Names and Types : " << std::endl;
    auto it = nameTypeMapGiven.begin();
    while(it != nameTypeMapGiven.end()){
        std::cout << it->first << " : " << it->second <<endl;
        it++;
    }
}

void parser::CircuitFileParser() {
    std::ifstream inputFileStream(circuitFileName);
    if(inputFileStream.fail()){ cout<<"\033[1;31m Input file did not open please check it \033[0m\n";
        system("pause");
    }
    int count = 0;
    if (inputFileStream.is_open()) {
        while (std::getline(inputFileStream, line, ';')) {
            std::istringstream lineStream(line);
            std::vector< std::string > vec;
            if (line != "") {
                if (count == 0) { // INPUT case
                    while (std::getline(lineStream, circuitInputName, ' ')) {
                        if (circuitInputName != "INPUT" || circuitInputName != " "){
                            if (circuitInputName != "INPUT"){
                                circuitInputNameVector.push_back(circuitInputName);
                            }
                        }
                    }
                } else if (count == 1) { // OUTPUT case
                    while (std::getline(lineStream, circuitOutputName, ' ')) {
                        if (circuitOutputName != "OUTPUT" || circuitOutputName != " ") {
                            if (circuitOutputName != "\nOUTPUT"){
                                circuitOutputNameVector.push_back(circuitOutputName);
                            }
                        }
                    }
                } else { // GATE case
                    std::getline(lineStream, gateType, ' ');
                    if (gateType == "\nand"){
                        gateType = "and";
                    } else if (gateType == "\nor"){
                        gateType = "or";
                    } else if (gateType == "\nxor"){
                        gateType = "xor";
                    } else if (gateType == "\nnot"){
                        gateType = "not";
                    }
                    std::getline(lineStream, gateName, ' ');
                    std::getline(lineStream, gateOutputName, ' ');
                    while (std::getline(lineStream, gateInputName, ' ')) {
                        vec.push_back(gateInputName);
                    }
                    outputPerGateMapGiven.insert({gateName, gateOutputName});
                    inputPerGateMapGiven.insert({gateName, vec});
                    adjancencyMapGiven.insert({gateName, 0});
                    nameTypeMapGiven.insert({gateName, gateType});
                    gateOutputNameVector.push_back(gateOutputName);
                }
            }
            count++;
        }
    } else {
        std::cerr << "Unable to open circuit file" << std::endl;
        std::terminate();
    }
    gateNumberGiven = count - 1;
    inputNumberGiven = circuitInputNameVector.size();
    outputNumberGiven = circuitOutputNameVector.size();
}

void parser::InputFileParser() {
    std::ifstream inputFileStream(inputFileName);
    if(inputFileStream.fail()){ cout<<"\033[1;31m Input file did not open please check it \033[0m\n";
        system("pause");
    }
    int i = 0;
    while (std::getline(inputFileStream, line, '\n')) {
        std::istringstream lineStream(line);
        if (line != " ") {
            if (i == 0) {
                simulationSizeGiven = stoi(line);
                i++;
            } else {
                int it = 0;
                int vec = stoi(line);
                while (it < inputNumberGiven) {
                    inputsMapGiven[circuitInputNameVector[it]].push_back(vec / int(pow(10,(inputNumberGiven - 1 - it))));
                    inputValue = vec / pow(10, (inputNumberGiven - 1 - it));
                    if (inputValue == 1) {
                        vec = vec - pow(10, (inputNumberGiven - 1 - it));
                    } else if (inputValue != 0) {
                        std::cerr << "\033[1;31m ERROR: Non binary value is found! " << inputFileName << " : " << "line ->" << i << " \033[0m\n" << std::endl;
                        std::terminate();
                    }
                    it++;
                }
            }
        }
    }
}
void parser::Init() {
    std::vector<int> outputs(simulationSizeGiven, 0);
    auto it = outputPerGateMapGiven.begin();
    while (it != outputPerGateMapGiven.end()) {
        outputMapGiven.insert({it->second, outputs});
        it++;
    }
}

void parser::GetArg(int argc, const char * argv[]) {
    const char *circuit = "-circuit";
    const char *inputs = "-inputs";
    std::string arg3 = reinterpret_cast<const char *>(argv[3]);
    if ( argc == 5 ){
        if (std::string(argv [1]) == circuit || std::string(argv [3]) == circuit){
            if (std::string(argv [1]) == circuit){
                circuitFileName = argv[2];
                //std::cout << " Cirtcuit file is check! 2 " << std::endl;
            } else {
                circuitFileName = argv[4];
                //std::cout << " Circuit file is check ! 4 " << std::endl;
            }
        } else {
            std::cerr << "\033[1;31m Error: Unknown type has been given! \033[0m\n" << std::endl;
            std::cerr << "Example : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
            std::terminate();
        } if (std::string(argv[1]) == inputs || std::string(argv[3]) == inputs){
            if (std::string(argv[3]) == inputs ){
                inputFileName = argv[4];
                //std::cout << " Inputs file is check ! 4 " << std::endl;
            } else {
                inputFileName = argv[2];
                //std::cout << " Inputs file is check ! 4 " << std::endl;
            }
        } else {
            std::cerr << "\033[1;31m Error: Unknown type has been given! \033[0m\n" << std::endl;
            std::cerr << "Example : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
            std::terminate();
        }
    } else {
        std::cerr << "\033[1;31m Error: Not enough arguments! \033[0m\n" << std::endl;
        std::cerr << "Example : $ ./DCS -circuit MyCircuit.txt -inputs MyInputs.txt" << std::endl;
        std::terminate();
    }
}