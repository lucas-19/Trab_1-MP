#ifndef PILHA_HPP
#define PILHA_HPP
#define CAPACITY 20

#include <iostream>

class ValueProps {
    public:
        int value; // valor do elemento
        ValueProps* next; // ponteiro que aponta para o proximo elemento 
};

class Stack {
    private:
        ValueProps* top; // Declarando a pilha em lista encadeada
        int size; // Declarando tamanho da pilha
        ValueProps* stack_s[CAPACITY]; // Declarando pilha estatica

    public:
        Stack* create(); //Funcao para criar pilha
        bool destroy(Stack *stack); // Funcao para destruir pilha
        void push(Stack *stack, ValueProps item); // Funcao para pushar um elemento na pilha
        ValueProps* pop(Stack *stack); // Funcao para popar o elemento topo da pilha
        ValueProps* topReturn(Stack *stack); // Funcao para retornar o topo da pilha
        bool isEmpety(Stack *stack); // Funcao auxiliar para detectar pilha vazia
        bool isFull(Stack* stack); // Funcao auxiliar para detectar pilha cheia
        
};


#endif // PILHA_HPP