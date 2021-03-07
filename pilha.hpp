#ifndef PILHA_HPP
#define PILHA_HPP
#define CAPACITY 20

#include <iostream>

class Value {
    public:
        int value;
        Value* next;
};

class Stack {
    private:
        Value* top;
        int size;
        int stackS[CAPACITY];

    public:
        Stack* create();
        void push(Stack *stack, Value item);
        Value* pop(Stack *stack);
        Value* topReturn(Stack *stack);
        bool isEmpety(Stack *stack);
        
};


#endif // PILHA_HPP