#include <iostream>
#include "../include/Dice.h"
#include <stdexcept>
#include <string.h>

namespace lab3{

int rand_t(){
    int s = rand()%6 + 1;
    return s;
}

DICE::DICE(){
    r_number = 0;
}

DICE::DICE(int r_number) {
    if (r_number < 0)
        throw std::length_error("Please enter tne number more than 0!");
    this->r_number = r_number;
    value = new int[r_number];
    for(int i = 0; i < r_number; i++) {
        value[i] = rand_t();
    }
}

DICE::DICE(const DICE& dice){
    r_number = dice.r_number;
    value = new int[r_number];
    for (int i = 0; i < r_number; i++)
        value[i] = dice.value[i];
}

DICE::DICE(DICE&& dice){
  r_number = dice.r_number;
  value = dice.value;
  dice.value = nullptr;
}

DICE::~DICE(){
    delete [] value;
}

DICE::DICE(const int *values, int r_number) {
    if (r_number < 0)
       throw std::length_error("Please enter tne number more than 0!");
    this->r_number = r_number;
    value = new int[r_number];
    for(int i = 0; i < r_number; i++)
        value[i] = values[i];
}

int DICE::get_r_number() const {
    return r_number;
}

int DICE::get_sum_of_dice() const {
    int sum = 0;
    for(int i = 0; i < r_number; i++)
        sum += value[i];
    return sum;
}

DICE& DICE::roll_dice() {
    for(int i = 0; i < r_number; i++){
        value[i] = rand_t();
    }
    return *this;
}

std::ostream& operator << (std::ostream& out, const DICE& dice){
    for(int i = 0; i < dice.r_number; i++)
        out << "Value #" << i + 1 <<": " << dice.value[i] << "\n";
    return out;
}

bool DICE::find_concurrence() const {
    for (int i = 0; i < r_number; i++){
        int current = value[i];
        for (int j = 0; j < r_number; j++){
            if (i == j) break;
            if (value [j] == current) return true;
        }
    }
    return false;
}

DICE& DICE::operator = (const DICE& dice){
  if (this != &dice){
    r_number = dice.r_number;
    delete [] value;
    value = new int[r_number];
    for (int i = 0; i < r_number; i++){
      value[i] = dice.value[i];
    }
  }
  return *this;
}

DICE& DICE::operator = (DICE&& dice){
  int number = r_number;
  r_number = dice.r_number;
  dice.r_number = number;
  int *ptr = value;
  value = dice.value;
  dice.value = ptr;
  return *this;
}

DICE& DICE::operator += (int value) {
    if (value < 1 || value > 6)
        throw std::invalid_argument("Invalid argument!");
    int *values = new int[r_number + 1];
    memcpy(values, this->value, r_number*sizeof(int));
    values[r_number] = value;
    r_number++;
    delete [] this->value;
    this->value = values;
    return *this;
}

DICE& DICE::operator -= (int value){
    int check = 0;
    if (value > 6 || value < 1)
        throw std::invalid_argument("Invalid argument!");
    for (int i = 0; i < r_number; i++){
        if (this->value[i] == value)
            check++;
        else this->value[i - check] = this->value[i];
    }
    if (check == 0)
        throw std::logic_error("No dice found!");
    r_number = r_number - check;
    int *values = new int[r_number];
    memcpy(values, this->value, r_number*sizeof(int));
    delete [] this->value;
    this->value = values;
    return *this;
}

int& DICE::operator [] (int value) {
    if (value > r_number || value < 1)
        throw std::invalid_argument("You don't have this dice!");
    return this->value[value - 1];
}
}
