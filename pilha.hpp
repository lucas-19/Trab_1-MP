#ifndef PILHA_HPP
#define PILHA_HPP
#define CAPACITY 20

#include <iostream>

class ValueProps {
    public:
        int value;
        ValueProps* next;
};

class Stack {
    private:
        ValueProps* top; 
        int size;
        ValueProps* stack_s[CAPACITY]; 

    public:
        Stack* create();
        bool destroy(Stack *stack);
        void push(Stack *stack, ValueProps item);
        ValueProps* pop(Stack *stack);
        ValueProps* topReturn(Stack *stack);
        bool isEmpety(Stack *stack);
        bool isFull(Stack* stack);
        
};


#endif // PILHA_HPP