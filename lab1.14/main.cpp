#include <iostream>
#include "Prog1.h"

using namespace Prog1;

int main() {
    struct Node *arr = nullptr;
    int *res = nullptr;
    int m, n;
    int choice;

    arr = Create_Matrix(m, n);
    if (!arr) {
       std::cout << "Incorrect data detected!" << std::endl;
       return 1;
    }

    do{
      printMenu();
      getNum(choice);
      if (choice == 4) break;
      if (choice > 4 || choice < 1){
        std::cout<<"Please choice right number..."<<std::endl;
      }else{
        std::cout<<"---------------------------------------------"<<std::endl;
        Print_Matrix("Sourced matrix:", arr, m, n);
        res = Create_Vector(arr, m, n, choice);
        if (!res) {
           std::cout << "Error in allocating memory!" << std::endl;
           return 1;
        }
        std::cout<<"---------------------------------------------"<<std::endl;
        Print_Vector("Result:", res, m);
      }
    }while (choice != 4);
    Erase_Matrix(arr);
    delete[] res;
    return 0;
}
