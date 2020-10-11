#include <iostream>

namespace lab3{
void print_menu();
void dialog();

template <class T>
int getNum(T &a){
    std::cin>>a;
    if (!std::cin.good()){
        return -1;
    }
    return 1;
}
}
