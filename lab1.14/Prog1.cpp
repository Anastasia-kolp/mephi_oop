#include <iostream>
#include "Prog1.h"

namespace Prog1 {
    void Create_Node(struct Node** matrix, int element, int row_index, int column_index) {
        struct Node *temp, *rows;
        temp = *matrix;

        if (!temp) {
           try {
               temp = new struct Node;
           }
           catch (std::bad_alloc &ba) {
               std::cout << "Error in allocating memory: " << ba.what() << std::endl;
               return;
           }
           temp->value = element;
           temp->row_position = row_index;
           temp->column_position = column_index;
           temp->next = nullptr;
           *matrix = temp;
        }
        else {
           while (temp->next) {
              temp = temp->next;
           }
           try {
               rows = new struct Node;
           }
           catch (std::bad_alloc &ba) {
               std::cout << "Error in allocating memory: " << ba.what() << std::endl;
               return;
           }
           rows->value = element;
           rows->row_position = row_index;
           rows->column_position = column_index;
           rows->next = nullptr;
           temp->next = rows;
        }
    }

    struct Node* Create_Matrix(int &rm, int &rn) {
        const char *pr = "";
        struct Node *matrix = nullptr;
        int m, n;
        int item;

        do {
            std::cout << pr;
            std::cout << "Enter the matrix dimensions: ";
            pr = "Invalid input, please try again!\n";
            if (getNum(m) < 0 || getNum(n) < 0) {
               return nullptr;
            }
        } while (m < 1 || n < 1);

        for (int i = 0; i < m; i++) {
            std::cout << "Enter the items for matrix row #" << (i + 1) << ": ";
            for (int j = 0; j < n; j++) {
                if (getNum(item) < 0) {
                   Erase_Matrix(matrix);
                   return nullptr;
                }
                else if (!item) {
                   continue;
                }
                else {
                   Create_Node(&matrix, item, i, j);
                }
            }
        }

        rm = m;
        rn = n;
        return matrix;
    }

    int Coordinates(struct Node* matrix, int row_index, int column_index) {
        struct Node *temp = matrix;

        while (temp) {
           if (temp->row_position == row_index && temp->column_position == column_index) {
              return temp->value;
           }
           temp = temp->next;
        }
        return 0;
    }

    void Print_Matrix(const char* msg, struct Node* matrix, int m, int n) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << Coordinates(matrix, i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void Print_Vector(const char* msg, int vector[], int m) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }

    struct Node* Erase_Matrix(struct Node* matrix) {
        struct Node *temp, *tmp;
        temp = matrix;

        while (temp) {
           tmp = temp;
           temp = temp->next;
           delete tmp;
        }
        return nullptr;
    }

    int NoSingleDigit(int a){
      if (a/10 != 0) return 1;
      return -1;
    }

    int Parity(int a){
      if (a%2 == 0) return 1;
      return -1;
    }

    int* Create_Vector(struct Node* matrix, int m, int n, int choice) {
        struct Node *temp = matrix;
        int *vector = nullptr;
        int sum = 0;
        try {
            vector = new int[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return nullptr;
        }

        if (choice == 1){
          for (int i = 0; i < m; i++){
            while (temp){
              if (temp->row_position == i && NoSingleDigit(temp->value) == 1){
                sum += temp->value;
              }
              if (temp->row_position != i) break;
              temp = temp->next;
            }
            vector[i] = sum;
            sum = 0;
          }
          return vector;
        }

        if (choice == 2){
          for (int i = 0; i < m; i++){
            while (temp){
              if (temp->row_position == i && Parity(temp->value) == 1){
                sum += temp->value;
              }
              if (temp->row_position != i) break;
              temp = temp->next;
            }
            vector[i] = sum;
            sum = 0;
          }
          return vector;
        }

        if (choice == 3){
          for (int i = 0; i < m; i++){
            while (temp){
              if (temp->row_position == i && NoSingleDigit(temp->value) == 1 && Parity(temp->value) == 1){
                sum += temp->value;
              }
              if (temp->row_position != i) break;
              temp = temp->next;
            }
            vector[i] = sum;
            sum = 0;
          }
          return vector;
        }
        return vector;
    }

    void printMenu(){
      std::cout<<"---------------------------------------------"<<std::endl;
      std::cout<<"1. Sum only numbers with more than two digits"<<std::endl;
      std::cout<<"2. Sum only even numbers"<<std::endl;
      std::cout<<"3. Sum even numbers with more than two digits"<<std::endl;
      std::cout<<"4. Exit"<<std::endl;
      std::cout<<"Your choice: ";
    }
}
