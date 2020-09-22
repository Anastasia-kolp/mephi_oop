namespace Prog1 {
    struct Node {
        int value;
        int row_position;
        int column_position;
        struct Node *next;
    };

    template <class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
           return -1;
        }
        return 1;
    }

    void Create_Node(struct Node**, int, int, int);
    struct Node* Create_Matrix(int &, int &);
    int NoSingleDigit(int);
    int Parity(int);
    int Coordinates(struct Node*, int, int);
    void Print_Matrix(const char*, struct Node*, int, int);
    void Print_Vector(const char*, int [], int);
    struct Node* Erase_Matrix(struct Node*);
    int* Create_Vector(struct Node*, int, int, int);
    void printMenu();
}
