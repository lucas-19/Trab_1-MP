#include "pilha.hpp"
using namespace std;

Stack* Stack::create() {
    Stack* s = reinterpret_cast<Stack*>(malloc(sizeof(Stack)));
    s->top = NULL;
    s->size = 0;
    cout << "Criado" << endl;
    return s;
}

void Stack::push(Stack* stack, Value item) {
    Value* n = reinterpret_cast<Value*>(malloc(sizeof(Value)));
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

Value* Stack::pop(Stack *stack){
    if(!isEmpety(stack)) {
        Value *aux = stack->top;
        stack->top = stack->top->next;
        free(aux);
        stack->size--;
        return stack->top;
    } else {
        throw invalid_argument("Pilha vazia! Nao eh possivel popar elemento");
        return NULL;
    }
}

Value* Stack::topReturn(Stack *stack) {
    if(!isEmpety(stack)) {
        return stack->top;
    } else{
        throw invalid_argument("Pilha vazia! Erro ao retornar topo");
    }
}

