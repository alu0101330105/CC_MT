/**
 * @file turingMachine.h
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief  Class that represents a Turing machine.
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "turingMachine.h"

/**
 * @brief Construct a new empty Turing Machine object.
 * @details This constructor is used to create a Turing Machine with empty values.
 */
TuringMachine::TuringMachine() {
  this->tape = std::vector<char>();
  this->states = std::vector<State>();
  this->alphabet = std::vector<char>();
  this->blankSymbol = '\0';
  this->initialState = "";
  this->finalStates = std::vector<std::string>();
}

/**
 * @brief Construct a new Turing Machine object.
 * @details This constructor is used to create a Turing Machine with the given values.
 * 
 * @param states - The states of the Turing Machine.
 * @param alphabet - The alphabet of the Turing Machine.
 * @param tapeAlphabet - The tape alphabet of the Turing Machine.
 * @param initialState - The initial state of the Turing Machine.
 * @param blankSymbol - The blank symbol of the Turing Machine.
 * @param finalStates - The final states of the Turing Machine.
 */
TuringMachine::TuringMachine(std::vector<State> states, std::vector<char> alphabet,
  std::vector<char> tapeAlphabet, std::string initialState, char blankSymbol,
  std::vector<std::string> finalStates) {

  this->tape = std::vector<char>();
  this->states = states;
  this->alphabet = alphabet;
  this->tapeAlphabet = tapeAlphabet;
  this->blankSymbol = blankSymbol;
  this->initialState = initialState;
  this->finalStates = finalStates;
}

/**
 * @brief Copy constructor of TuringMachine.
 * @details This constructor is used to create a TuringMachine with the values of another TuringMachine.
 * 
 * @param turingMachine - The TuringMachine to be copied.
 */
TuringMachine::TuringMachine(const TuringMachine& turingMachine) {
  this->tape = turingMachine.getTape();
  this->states = turingMachine.getStates();
  this->alphabet = turingMachine.getAlphabet();
  this->tapeAlphabet = turingMachine.getTapeAlphabet();
  this->blankSymbol = turingMachine.getBlankSymbol();
  this->initialState = turingMachine.getInitialState();
  this->finalStates = turingMachine.getFinalStates();
}

/**
 * @brief Get the states of the Turing Machine.
 * @details This method returns the states of the Turing Machine.
 * 
 * @return std::vector<State> 
 */
std::vector<State> TuringMachine::getStates() const {
  return this->states;
}

/**
 * @brief Get the alphabet of the Turing Machine.
 * @details This method returns the alphabet of the Turing Machine.
 * 
 * @return std::vector<char> 
 */
std::vector<char> TuringMachine::getAlphabet() const {
  return this->alphabet;
}

/**
 * @brief Get the tape alphabet of the Turing Machine.
 * @details This method returns the tape alphabet of the Turing Machine.
 * 
 * @return std::vector<char> 
 */
std::vector<char> TuringMachine::getTapeAlphabet() const {
  return this->tapeAlphabet;
}

/**
 * @brief Get the initial state of the Turing Machine.
 * @details This method returns the initial state of the Turing Machine.
 * 
 * @return std::string 
 */
std::string TuringMachine::getInitialState() const {
  return this->initialState;
}

/**
 * @brief Get the blank symbol of the Turing Machine.
 * @details This method returns the blank symbol of the Turing Machine.
 * 
 * @return char 
 */
char TuringMachine::getBlankSymbol() const {
  return this->blankSymbol;
}

/**
 * @brief Get the final states of the Turing Machine.
 * @details This method returns the final states of the Turing Machine.
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> TuringMachine::getFinalStates() const {
  return this->finalStates;
}

/**
 * @brief Get the tape of the Turing Machine.
 * @details This method returns the tape of the Turing Machine.
 * 
 * @return std::vector<char> 
 */
std::vector<char> TuringMachine::getTape() const {
  return this->tape;
}

/**
 * @brief Set the states of the Turing Machine.
 * @details This method sets the states of the Turing Machine.
 * 
 * @param states - The states of the Turing Machine.
 */
void TuringMachine::setStates(std::vector<State> states) {
  this->states = states;
}

/**
 * @brief Set the alphabet of the Turing Machine.
 * @details This method sets the alphabet of the Turing Machine.
 * 
 * @param alphabet - The alphabet of the Turing Machine.
 */
void TuringMachine::setAlphabet(std::vector<char> alphabet) {
  this->alphabet = alphabet;
}

/**
 * @brief Set the tape alphabet of the Turing Machine.
 * @details This method sets the tape alphabet of the Turing Machine.
 * 
 * @param tapeAlphabet - The tape alphabet of the Turing Machine.
 */
void TuringMachine::setTapeAlphabet(std::vector<char> tapeAlphabet) {
  this->tapeAlphabet = tapeAlphabet;
}

/**
 * @brief Set the initial state of the Turing Machine.
 * @details This method sets the initial state of the Turing Machine.
 * 
 * @param initialState - The initial state of the Turing Machine.
 */
void TuringMachine::setInitialState(std::string initialState) {
  this->initialState = initialState;
}

/**
 * @brief Set the blank symbol of the Turing Machine.
 * @details This method sets the blank symbol of the Turing Machine.
 * 
 * @param blankSymbol - The blank symbol of the Turing Machine.
 */
void TuringMachine::setBlankSymbol(char blankSymbol) {
  this->blankSymbol = blankSymbol;
}

/**
 * @brief Set the final states of the Turing Machine.
 * @details This method sets the final states of the Turing Machine.
 * 
 * @param finalStates - The final states of the Turing Machine.
 */
void TuringMachine::setFinalStates(std::vector<std::string> finalStates) {
  this->finalStates = finalStates;
}

/**
 * @brief Set the tape of the Turing Machine.
 * @details This method sets the tape of the Turing Machine. It does not reset the head position nor
 * input the blank symbol at the beginning and end of the tape.
 * 
 * @param tape - The tape of the Turing Machine.
 */
void TuringMachine::setTape(std::vector<char> tape) {
  this->tape = tape;
}

/**
 * @brief Set the tape of the Turing Machine.
 * @details This method sets the tape of the Turing Machine.
 * 
 * @param tape - The tape of the Turing Machine.
 */
void TuringMachine::setTape(std::string tape) {
  this->tape = std::vector<char>();
  this->headPosition = 1;
  this->tape.push_back(this->blankSymbol);
  for (int i = 0; i < tape.length(); i++) {
    this->tape.push_back(tape[i]);
  }
  this->tape.push_back(this->blankSymbol);
}

/**
 * @brief Read the tape of the Turing Machine.
 * @details This method reads the tape of the Turing Machine.
 * 
 * @return char 
 */
char TuringMachine::readTape() {
  return this->tape[this->headPosition];
}

/**
 * @brief Write on the tape of the Turing Machine.
 * @details This method writes on the tape of the Turing Machine.
 * 
 * @param symbol - The symbol to be written on the tape.
 */
void TuringMachine::writeTape(char symbol) {
  this->tape[this->headPosition] = symbol;
  if(this->headPosition == this->tape.size() - 1) {
    this->tape.push_back(this->blankSymbol);
  }
}

/**
 * @brief Move the head of the Turing Machine.
 * @details This method moves the head of the Turing Machine. It does not allow the head to go to the left of the first position.
 * 
 * @param movement - The movement of the head.
 */
void TuringMachine::moveHead(char movement) {
  if (movement == 'R') {
    this->headPosition++;
  } else if (movement == 'L') {
    this->headPosition--;
  } else if (movement == 'S') // Do nothing

  if (this->headPosition < 0) {
    this->headPosition = 0;
  }
}

/**
 * @brief Reset the head of the Turing Machine.
 * @details This method resets the head of the Turing Machine.
 */
void TuringMachine::resetHead() {
  this->headPosition = 0;
}

/**
 * @brief Get the posible transitions of the Turing Machine.
 * @details This method returns the posible transitions of the Turing Machine.
 * 
 * @param stateName - The name of the state.
 * @param symbol - The symbol that triggers the transition.
 * @param tapeSymbol - The symbol that must be on the top of the stack to trigger the transition.
 * @return std::vector<Transition> 
 */
std::vector<Transition> TuringMachine::getPosibleTransitions(std::string stateName, char symbol) const {
  std::vector<Transition> posibleTransitions;
  for (int i = 0; i < this->states.size(); i++) {
    if (this->states[i].getName() == stateName) {
      std::vector<Transition> transitions = this->states[i].getTransitions();
      for (int j = 0; j < transitions.size(); j++) {
        if (transitions[j].getSymbol() == symbol) {
          posibleTransitions.push_back(transitions[j]);
        }
      }
    }
  }
  return posibleTransitions;
}

/**
 * @brief Get the opposite direction of the given direction.
 * @details This method returns the opposite direction of the given direction.
 * 
 * @param direction - The direction.
 * @return char 
 */
char TuringMachine::getOppositeDirection(char direction) const {
  if (direction == 'R') {
    return 'L';
  } else if (direction == 'L') {
    return 'R';
  } else {
    return 'S';
  }
}

/**
 * @brief Check if the Turing Machine accepts the current tape.
 * @details This method checks if the Turing Machine accepts the current tape.
 * 
 * @param trace 
 * @return bool - True if the Turing Machine is accepted, false otherwise.
 */
bool TuringMachine::isAccepted(bool trace) {
  if(trace) {
    std::cout << "Tape: ";
    for (int i = 0; i < this->tape.size(); i++) {
      if (i == headPosition) {
        std::cout << "\033[1;31m" << this->tape[i] << "\033[0m";
      } else {
        std::cout << this->tape[i];
      }
    }
    std::cout << "\n";
  }
  return isAccepted(initialState, trace);
}

bool TuringMachine::isAccepted(std::string currentState, bool trace) {
  char currentTapeSymbol = readTape();
  std::vector<Transition> possibleTransitions = getPosibleTransitions(currentState, currentTapeSymbol);

  if(trace && possibleTransitions.size() == 0) {
    std::cout << "State " << currentState << " has no transitions for symbol " << currentTapeSymbol << "\n";
  }

  for (const Transition& transition : possibleTransitions) {
    std::string nextState = transition.getDestiny();
    char writeSymbol = transition.getNewTapeSymbol();
    char moveDirection = transition.getMovement();

    writeTape(writeSymbol);
    moveHead(moveDirection);
    if (trace) {
      std::cout << currentState << " -> " << nextState << " [" << currentTapeSymbol << " -> " << writeSymbol << ", " << moveDirection << "]" << std::endl;
      // std::cout << "Tape: " << this->getTape() << std::endl;
      std::cout << "Tape: ";
      for (int i = 0; i < this->tape.size(); i++) {
        if (i == headPosition) {
          std::cout << "\033[1;31m" << this->tape[i] << "\033[0m";
        } else {
          std::cout << this->tape[i];
        }
      }
      std::cout << "\n";
    }


    if (isAccepted(nextState, trace)) {
      return true;
    }

    // Undo the changes made to the tape and head position
    writeTape(currentTapeSymbol);
    moveHead(getOppositeDirection(moveDirection));
  }

  if (std::find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end()) {
    if (trace) {
      std::cout << "State " << currentState << " is final\n";
    }
    return true;
  }

  return false;
}