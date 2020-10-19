#pragma once

#include <iostream>

namespace lab3{

class DICE{
private:
    int *value;
    int r_number;
public:
    DICE();
    explicit DICE(int r_number);
    DICE(const int *values, int r_number);
    DICE(const DICE& dice);
    DICE(DICE&& dice);
    ~DICE();
    int get_r_number() const;
    int get_sum_of_dice() const;
    friend std::ostream& operator <<(std::ostream& out, const DICE& dice);
    DICE& roll_dice();
    bool find_concurrence() const;
    DICE& operator = (const DICE& dice);
    DICE& operator = (DICE&& dice);
    DICE& operator += (int value);
    DICE& operator -= (int value);
    int& operator [] (int value);
};
}
