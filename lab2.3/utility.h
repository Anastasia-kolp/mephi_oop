#include <iostream>

namespace lab2{
  void print_menu();

  template <class T>
  int getNum(T &a){
      std::cin>>a;
      if (!std::cin.good()){
          return -1;
      }
      return 1;
  }
}
