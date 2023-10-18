/**
 * @file transition.h
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a transition of a Turig machine.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <vector>
#include <string>

class Transition {
  private:
    std::string origin = "";
    std::string destiny = "";
    char symbol = '\0';
    char newTapeSymbol = '\0';
    char movement = '\0';
  
  public:
    Transition();
    ~Transition() {};
    Transition(std::string origin, std::string destiny,
      char symbol, char newTapeSymbol, char movement);
    Transition(const Transition& transition);
    std::string getOrigin() const;
    std::string getDestiny() const;
    char getSymbol() const;
    char getNewTapeSymbol() const;
    char getMovement() const;
    void setOrigin(std::string origin);
    void setDestiny(std::string destiny);
    void setSymbol(char symbol);
    void setNewTapeSymbol(char newTapeSymbol);
    void setMovement(char movement);
    std::string toString() const;

};

#endif // TRANSITION_H