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

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include "state.h"
#include <algorithm>


class TuringMachine {
  private:
    // (M = (Q, ∑, Γ, s, b, F, δ))
    std::vector<State> states;
    std::vector<char> alphabet;
    std::vector<char> tapeAlphabet;
    std::string initialState;
    char blankSymbol;
    std::vector<std::string> finalStates;
    std::vector<char> tape;
    int headPosition = 0;

  public:
    TuringMachine();
    ~TuringMachine() {};
    TuringMachine(std::vector<State> states, std::vector<char> alphabet,
      std::vector<char> tapeAlphabet, std::string initialState, char blankSymbol,
      std::vector<std::string> finalStates);
    TuringMachine(const TuringMachine& turingMachine);

    std::vector<State> getStates() const;
    std::vector<char> getAlphabet() const;
    std::vector<char> getTapeAlphabet() const;
    std::string getInitialState() const;
    char getBlankSymbol() const;
    std::vector<std::string> getFinalStates() const;
    std::vector<char> getTape() const;

    void setStates(std::vector<State> states);
    void setAlphabet(std::vector<char> alphabet);
    void setTapeAlphabet(std::vector<char> tapeAlphabet);
    void setInitialState(std::string initialState);
    void setBlankSymbol(char blankSymbol);
    void setFinalStates(std::vector<std::string> finalStates);
    void setTape(std::vector<char> tape);
    void setTape(std::string tape);

    char readTape();
    void writeTape(char symbol);
    void moveHead(char movement);
    void resetHead();

    char getOppositeDirection(char direction) const;
    std::vector<Transition> getPosibleTransitions(std::string stateName, char symbol) const;
    bool isAccepted(bool trace = false);
    bool isAccepted(std::string currentState, bool trace = false);
};


#endif // TURING_MACHINE_H