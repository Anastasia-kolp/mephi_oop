#include "utility.h"
#include "Dice.h"
#include <iostream>

namespace lab3{

void print_menu(){
    std::cout << "------------------------------------" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Roll the dice" << std::endl;
    std::cout << "2. Add dice with specific value" << std::endl;
    std::cout << "3. Remove dice with specific value" << std::endl;
    std::cout << "4. Print the value of specific dice" << std::endl;
    std::cout << "5. Check the concurrency" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void dialog(){
    int check;
    int n;
    while (true){
        std::cout << "What number of dice do you want?" << std::endl;
        getNum(n);
        try {
            DICE dice(n);
            break;
        }
        catch (const std::length_error& er) {
            std::cerr << "Error: " << er.what() << std::endl;
        }
    }
    DICE dice(n);
    std::cout << dice << std::endl;
    int m;
    while (true){
        print_menu();
        std::cout << "Your choice:";
        getNum(check);
        switch (check) {
        case 0:
            return;
        case 1:
            dice.roll_dice();
            std::cout << dice << std::endl;
            std::cout << "The sum of values = " << dice.get_sum_of_dice() << std::endl;
            break;
        case 2:
            std::cout << "Enter the value of dice:";
            getNum(m);
            try{
                dice += m;
                std::cout << dice << std::endl;
                std::cout << "The sum of values = " << dice.get_sum_of_dice() <<
                std::endl;
            }
            catch (const std::length_error& er) {
                std::cerr << "Error: " << er.what() << std::endl;
            }
            catch (const std::invalid_argument& er) {
                std::cerr << "Error: " << er.what() << std::endl;
            }
            break;
        case 3:
            std::cout << "Enter the value of dice:";
            getNum(m);
            try {
                dice -= m;
                std::cout << dice << std::endl;
                std::cout << "The sum of values = " << dice.get_sum_of_dice() << std::endl;
            }
            catch (const std::invalid_argument& er) {
                std::cerr << "Error: " << er.what() << std::endl;
            }
            catch (const std::logic_error& er){
                std::cerr << "Error: " << er.what() << std::endl;
            }
            break;
        case 4:
            int s;
            std::cout << "Enter number of dice:";
            getNum(m);
            try{
                s = dice [m];
                std::cout << "The value of dice #" << m << " = " << s << std::endl;
            }
            catch (const std::invalid_argument& er){
                std::cerr << "Error: " << er.what() << std::endl;
            }
            break;
        case 5:
            std::cout << dice << std::endl;
            if (dice.find_concurrence())
                std::cout << "You have concurrence!" << std::endl;
            else std::cout << "Don't have concurrence..." << std::endl;
            break;
        default:
            std::cout << "Wrong input! Please try again..." << std::endl;
        }
    }
}
}
