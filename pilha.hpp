#ifndef PILHA_HPP
#define PILHA_HPP
#define CAPACITY 20

#include <istream>

class ValueD {
    public:
        int value;
        ValueD* next;
};

class ValueS {
    public:
        int value;
};

class StackD {
    private:
        ValueD* top;
        int size;

    public:
        StackD* createStack();
        ValueD* push(StackD *stackD, ValueD item);
        ValueD* pop(StackD *stackD);
        ValueD* top(StackD *stackD);
        ValueD* isEmpety(StackD *stackD);
};

class StackS {
    private:
        int size, top, capacity;
        ValueS stackS[CAPACITY];
    public:
        ValueS* push(StackS *stackS, ValueS item);
        ValueS* pop(StackS *stackS);
        ValueS* top(StackS *stackS);
        ValueS* isEmpety(StackS *stackS);
};


#endif // PILHA_HPP