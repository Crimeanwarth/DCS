# DCS
This project is the part of the curriculum, MSc. Embedded Electronics Systems degree, at University of Montpellier/LIRMM laboratoires.   The final goal of the project is to have a complete simulator that can execute from a netlist that is of a Digital Circuit.  

#TODO :Image will be posted here

The simulator is made out of 4 parts:

- Parsing the netlist that is given (which describes the digital circuit)(.txt file)
- Parsing the simulation values that are given(.txt)
- Modelisation of the circuit after parsing the .txt file.
- Simulation: creating and appending(logging) a .txt file with the ouput values of the circuit design.

## 1. Modelisation of logic gates 

We are going to consider that our circuits are made up from simple logic gates such as:
- AND
- OR 
- NOT
- XOR

We will create a pecking order of classes in order to to modelize  all the logic gates. It is important to note that we can have an endless number of input but eery gate can have only one output.

We will define the common interface of the hierarchy with the following methods:

- printInfo : It prints the names and the numbers of the gates , also their input values for simulation with their outputs.

- setInput: Which atrributes a value an input.

- calculateOutput: calculates the output values of the gate.

## 2. Circuit Model

#TODO: Insert image.

Every circuit is composed of certain number of inputs (#EP), certain number of gates(#PL) and certain number of outputs(#SP).

With our exemple we have:

- #EP = 6
- #PL = 6
- #SP = 3

The circuit can be modelized with a graph. Every top point of the graph would be considered as inputs and every end is an output. The lines are considered as wires, here is the result:

#TODO: Insert the graph of the model circuit

In order to représente the graph in memory we will use our knowledge from an other course (Graphs and Algorithms by Mr. Rouzeyre)(we will uses adjecence and incident matrices). For the représentation of the circuit we will create a friendly class to our LogicGates called "Graph".

## 3. Parsing the Circuit Netlist

The syntax of the .txt file that will describe the netlist of the circuit model is the following:

-Exemple of the syntax:

‘INPUT E1 E2 ... EN;
 OUTPUT S1 S2 ... SK;
 Type LogicGate1 SP EP1 EP2 ... EPZ1;
 Type LogicGate2 SP EP1 EP2 ... EPZ2;
 ...
 Type LogicGateW SP EP1 EP2 ... EPZW;

The first line defines the primal inputs,every name is separated with space and lines are finished by ‘;‘.
The second line defines the primal outputs.
From the third line, we describe the logic gates. Every gate is described in one line:

- Type: AND, OR, NOT, XOR
- Name: Name of the gate
- Output: Name of the output
- Array of Inputs: (EP1 ... EPZi) array of the names of the inputs.

and as usual every line finishes with ‘;‘.

- Exemple of the 2nd graph:
‘ INPUT E1 E2 E3 E4 E5 E6;
  OUTPUT S1 S2 S3;
  and P1 a E1 E2;
  or P2 b E3 E4;
  and P3 c b E5;
  or P4 S1 a c;
  not P5 S2 c;
  or P6 S3 c E6;‘

There will be methodes created under the "Graph" class in order to parse the .txt file.

## 4. Parsing of the values

The .txt file that containes the logic values which will be introduced to the input points of our circuit design has the following syntax:

‘NumberOfVectors
 X1X2 ... XN
 Y1Y2 ... YN
 ...
 K1K2 ... KW‘

The first line specifies the number of inputs. From the second line, we start to define the vectors with their respected gate. Every gate can recieve only the values '1/0'. The dimension of the vector of a gate depends on the number of the inputs it posses(#EP). The Nth member of the vector corresponds to Nth input of the respected gate.

Exemple of the graph:

For two vectors:

‘2
 000000
 000100‘ 

We will create a "ReadWrite" class for memory methode of the vectors and a parse class for parsing the .txt files.

## 5. Simulation

This is the hearth of our program, the simulation of the designed circuit. It consists of the application of every vector given to the primal inputs and get the outputs.

For this case we will use the DFS (Depth-first search). The idea is to use the DFS for every primal input. While executing the DFS we will go throught a lot of tops until we arrive to the outputs. For these calculations we will use the methods:

- CalculateOutput: calculates the output that is asked for.

- SetInput: attributes the outputs to the inputs they belong to.
 
The pseudo code of the simulation is the following:

‘ for everyVector V {
       V => Inputs;
       for everyInput EP{
             DFS(EP);
       }
       Print(Outputs);
  }‘

This part will be implimented in to the ‘graph‘ class.

