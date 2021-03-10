#include "pilha.hpp"
using namespace std;
#define DINAMIC true



#if DINAMIC
    Stack* Stack::create() {
        Stack* s = reinterpret_cast<Stack*>(malloc(sizeof(Stack)));
        s->top = NULL;
        s->size = 0;
        cout << "Pilha dinamica criada" << endl;
        return s;
    }

    bool Stack::destroy(Stack *stack) {
        if(!stack->isEmpety(stack)) {
            while(stack->top != NULL) {
                stack->pop(stack);
            }
            free(stack);
            stack = NULL; 
            return true;
            
        } else {
            cout << "Erro ao deletar pilha, pilha vazia" << endl;
            return false;
        }
    }

    void Stack::push(Stack* stack, ValueProps item) {
        ValueProps* n = reinterpret_cast<ValueProps*>(malloc(sizeof(ValueProps)));
        n->value = item.value;
        n->next = stack->top;
        stack->top = n;
        stack->size++;
    }

    bool Stack::isEmpety(Stack* stack) {
        if(stack->top == NULL){
            return true;
        } else{
            return false;
        }
    }

    ValueProps* Stack::pop(Stack *stack){
        if(!isEmpety(stack)) {
            ValueProps *aux = stack->top;
            stack->top = stack->top->next;
            free(aux);
            stack->size--;
            return stack->top;
        } else {
            throw invalid_argument("Pilha vazia! Nao eh possivel popar elemento");
            return NULL;
        }
    }

    ValueProps* Stack::topReturn(Stack *stack) {
        if(!isEmpety(stack)) {
            return stack->top;
        } else{
            throw invalid_argument("Pilha vazia! Erro ao retornar topo");
        }
    }

#else

    Stack* Stack::create() {
        Stack *s = reinterpret_cast<Stack*>(malloc(sizeof(Stack)));
        s->size = 0;
        cout << "Pilha estatica criada" << endl;
        return s;
    }

    bool Stack::destroy(Stack *stack) {
        if(!stack->isEmpety(stack)) {
            while(stack->top != NULL) {
                stack->pop(stack);
            }
            if (stack->top == NULL) {
                cout << "Todos os elementos foram retirados" << endl;
            }
            stack = NULL; 
            free(stack);
            return true;
        } else {
            cout << "Erro ao deletar pilha, pilha vazia" << endl;
            return false;
        }
    }

    bool Stack::isFull(Stack* stack) {
        int size = stack->size;
        if(size >= CAPACITY) {
            return true;
        } else {
            return false;
        }
    }

    bool Stack::isEmpety(Stack *stack) {
        int size = stack->size;
        if(size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void Stack::push(Stack* stack, ValueProps item) {
        ValueProps* n = reinterpret_cast<ValueProps*>(malloc(sizeof(ValueProps)));
        n->value = item.value;
        int size = stack->size;
        if(!isFull(stack)) {
            
            stack->stack_s[size] = n;
            stack->size++;
        } else {
            throw invalid_argument("Pilha cheia! Impossivel de adicionar elemento");
        }
    }

    ValueProps* Stack::pop(Stack *stack) {
        int size = stack->size;
        if(isEmpety(stack)) {
            throw invalid_argument("Pilha vazia! Nao eh possivel popar elemento");
        } else {
        ValueProps *aux = stack->stack_s[size - 1];
        free(aux);
        stack->size--;
        return stack->stack_s[size];
        }

    }

    ValueProps* Stack::topReturn(Stack *stack) {
        int size = stack->size;
        
        if(!isEmpety(stack)) {
            return stack->stack_s[size - 1];
        } else{
            throw invalid_argument("Pilha vazia! Erro ao retornar topo");
        }
    }

#endif 

