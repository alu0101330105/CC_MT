/**
 * @file main.cc
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Main program for the pushdown automata 
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/turingMachine.h"
#include <fstream>
#include <sstream>

void readFromFile(std::string filename, TuringMachine& MT) {
  std::fstream file;
  file.open(filename, std::ios::in);

  if(!file.is_open()) {
    std::cerr << "Error oppening file\n";
    exit(EXIT_FAILURE);
  }

  // File Format:
  // # coments
  // states
  // alphabet
  // tape alphabet
  // initial state
  // blank symbol
  // final states
  // transitions


  std::string line = "";
  std::getline(file, line);
  while(line[0] == '#') {
    getline(file, line);
  }


  std::vector<std::string> statesRaw;
  std::istringstream ss(line);
  std::string token;
  char delimeter = ' ';
  while(std::getline(ss, token, delimeter)) {
    statesRaw.push_back(token);
  }

  std::getline(file, line);
  ss.clear();
  ss.str(line);
  std::vector<char> alphabet;
  while(std::getline(ss, token, delimeter)) {
    alphabet.push_back(token[0]);
  }

  std::getline(file, line);
  ss.clear();
  ss.str(line);
  std::vector<char> tapeAlphabet;
  while(std::getline(ss, token, delimeter)) {
    tapeAlphabet.push_back(token[0]);
  }

  std::string initialState = "";
  std::getline(file, initialState);

  std::string blankSymbol = "";
  std::getline(file, blankSymbol);  


  std::vector<std::string> finalStates;
  std::getline(file, line);
  ss.clear();
  ss.str(line);
  while(std::getline(ss, token, delimeter)) {
    finalStates.push_back(token);
  }

  // building states
  std::vector<State> stateVector;
  for(std::string name : statesRaw) {
    State state(name);
    if(name == initialState) state.setInitial(true);
    for(std::string final : finalStates) {
      if(name == final) state.setFinal(true);
    }
    stateVector.push_back(state);
  }

  // transitions format:
  // [origin] [tape symbol] [destination] [new tape symbol] [movement]
  std::vector<Transition> transitions;
  while(std::getline(file, line)) {
    ss.clear();
    ss.str(line);
    std::vector<std::string> trans;
    while(std::getline(ss, token, delimeter)) {
      trans.push_back(token);
    }

    Transition newTrans(trans[0], trans[2], trans[1][0], trans[3][0], trans[4][0]);
    // std::cout << "debug transition " << newTrans.toString() << "\n";
    transitions.push_back(newTrans);        
  }

  // for(Transition t : transitions) std::cout << "Debug Transitiosn: " + t.toString() + "\n";


  for(Transition actual : transitions) {
    for(int i = 0; i < stateVector.size(); i++) {
      // std::cout << "Debug Transitiosn: " + actual.toString() + "\n";
      // std::cout << "Debug State: " + stateVector[i].getName() + "\n";
      if(actual.getOrigin() == stateVector[i].getName()) {
        // std::cout << "found " + actual.getOrigin() + " for state " + stateVector[i].getName() + "\n";
        // check if transitions are legal:
        // check for ilegal write symbol
        if(std::find(tapeAlphabet.begin(), tapeAlphabet.end(), actual.getNewTapeSymbol()) == tapeAlphabet.end()) {
          std::cerr << "Error: new tape symbol not in tape alphabet\n";
          std::cerr << "Transition: " + actual.toString() + "\n";
          exit(EXIT_FAILURE);
        }
        // check for ilegal read symbol
        if(std::find(tapeAlphabet.begin(), tapeAlphabet.end(), actual.getSymbol()) == tapeAlphabet.end()) {
          std::cerr << "Error: tape symbol not in tape alphabet\n";
          std::cerr << "Transition: " + actual.toString() + "\n";
          exit(EXIT_FAILURE);
        }
        // check for ilegal origin or destiny states
        if(std::find(statesRaw.begin(), statesRaw.end(), actual.getOrigin()) == statesRaw.end() ||
           std::find(statesRaw.begin(), statesRaw.end(), actual.getDestiny()) == statesRaw.end()) {
          std::cerr << "Error: origin or destiny state not in states\n";
          std::cerr << "Transition: " + actual.toString() + "\n";
          exit(EXIT_FAILURE);
        }
        stateVector[i].addTransition(actual);
        // std::cout << "checking state transition insertion: ";
        // for(Transition t : stateVector[i].getTransitions()) std::cout << t.toString() + "\n";
      }
    } 
  }

  // Check for inconsistencies
  // blank symbol in tape alphabet
  // initial state in states
  // final states in states

  if(std::find(tapeAlphabet.begin(), tapeAlphabet.end(), blankSymbol[0]) == tapeAlphabet.end()) {
    std::cerr << "Error: blank symbol not in tape alphabet\n";
    exit(EXIT_FAILURE);
  }

  bool initialStateFound = false;
  for(State s : stateVector) {
    if(s.getName() == initialState) {
      initialStateFound = true;
      break;
    }
  }
  if(!initialStateFound) {
    std::cerr << "Error: initial state not in states\n";
    exit(EXIT_FAILURE);
  }

  for(std::string final : finalStates) {
    bool finalStateFound = false;
    for(State s : stateVector) {
      if(s.getName() == final) {
        finalStateFound = true;
        break;
      }
    }
    if(!finalStateFound) {
      std::cerr << "Error: final state not in states\n";
      exit(EXIT_FAILURE);
    }
  }


  MT.setAlphabet(alphabet);
  MT.setTapeAlphabet(tapeAlphabet);
  MT.setStates(stateVector);
  MT.setInitialState(initialState);
  MT.setBlankSymbol(blankSymbol[0]);
  MT.setFinalStates(finalStates);
  

  std::cout << "read automata:\n  alphabet = {";
  for(char c : MT.getAlphabet()) {
    std::cout << c << " ";
  }
  std::cout << "}\n  tape alphabet = {";
  for(char c : MT.getTapeAlphabet()) {
    std::cout << c << " ";
  }

  std::cout << "}\n  blank simbol = {" << MT.getBlankSymbol();

  std::cout << "}\n  states = {";
  for(State s : MT.getStates()) {
    std::cout << s.getName() << " ";
  }

  std::cout << "}\n  initial state = {" + MT.getInitialState();
  std::cout << "}\n  final states = {";
  for(std::string s : MT.getFinalStates()) {
    std::cout << s << " ";
  }

  std::cout << "}\n  transitions = {\n";
  for(State s : MT.getStates()) {
    for(Transition t : s.getTransitions()) {
      std::cout << "    " + t.toString() + "\n";
    }
  }
  std::cout << "  }\n";

}

void testLoop(TuringMachine& MT, bool trace) {
  std::cout << (trace ? "$trace" : "$noTrace") << std::endl;

  std::string word = "";
  while(true) {
    std::cout << ">";
    std::cin >> word;
    if(word == ":q") break;
    MT.setTape(word);
    bool accepted = MT.isAccepted(trace);
    
    std::cout << "Result: ";
    for (int i = 0; i < MT.getTape().size(); i++) {
      if (i == MT.getHeadPosition()) {
        std::cout << "\033[1;31m" << MT.getTape()[i] << "\033[0m";
      } else {
        std::cout << MT.getTape()[i];
      }
    }
    std::cout << "\n";

    std::cout << "The word " + word + " is";
    if(!accepted) std::cout << " not";
    std::cout << " accepted by the languaje.\n";
  }
}

int main(int argc, char* argv[]) {
  std::string filename = argv[1];
  TuringMachine MT;
  bool trace = false;
  if(argc > 2) trace = bool(argv[2]);
  std::cout << filename + (trace ? " trace" : " noTrace") + "\n";

  readFromFile(filename, MT);
  
  testLoop(MT, trace);
}