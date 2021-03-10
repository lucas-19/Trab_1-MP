#include "pilha.hpp"
using namespace std;

bool testCreate() { //okS
    Stack* aux = NULL;
    aux = aux->create();
    if(aux != NULL) {
        free(aux);
        return true;
    } else {
        return false;
    }    
}

bool testPush() {
    
    bool status = false;
    try {
        ValueProps element;
        element.value = 10;
        Stack* aux = NULL;
        aux = aux->create();
        aux->push(aux, element);
        
        if (aux->topReturn(aux)->value == element.value) {
            status = true;
            aux->destroy(aux);
        }
    }
    catch(invalid_argument& ia) {
        cout << ia.what() << endl;
    }
    return status;
}

bool testDestroy() {
    bool status = false;
    try {
        Stack* aux = NULL;
        aux = aux->create();
        ValueProps item;
        item.value = 419;
        for(int i = 0; i < 10; i++) {
            aux->push(aux, item);
        }
        status = aux->destroy(aux);
        
    } catch(invalid_argument& ia) {
        status = false; 
        cout << ia.what() << endl;
    }
    return status;
}

bool testPop() {
    bool status = false;
    int size = 3;
    try {
        Stack* aux = NULL;
        aux = aux->create();
        ValueProps item[3];
        for(int i = 0; i < size; i++) {
            item[i].value = i;
            aux->push(aux, item[i]);
        }

        for(int i = size - 1; i >= 0; i--) {
            if(aux->topReturn(aux)->value == item[i].value) {
                aux->pop(aux);
            }
            status = aux->isEmpety(aux);
        }
        free(aux);
    }
    catch(invalid_argument& ia) {
        cout << ia.what() << endl;
    }
    return status;
}

bool testTop() {
    bool status = false;
    try {
        Stack* aux = NULL;
        aux = aux->create();
        ValueProps item;
        item.value = 419; 
        aux->push(aux, item);
        if(aux->topReturn(aux)->value == item.value) {
            status = true;
            aux->destroy(aux);
        }
    }
    catch(invalid_argument& ia) {
        cout << ia.what() << endl;
    }
    return status;
}


int main() {
    bool teste;
    cout << "teste Create- " << endl;
    teste = testCreate();
    cout << "Resultado: " << teste << endl;

    cout << "teste Destroy- " << endl;
    teste = testDestroy();
    cout << "Resultado: " << teste << endl;
    
    cout << "teste Push- " << endl;
    teste = testPush();
    cout << "Resultado: " << teste << endl;

    cout << "teste Pop-" << endl;
    teste = testPop();
    cout << "testPop: " << teste << endl;

    cout << "teste Top-" << endl;
    teste = testTop();
    cout << "Resultado: " << teste << endl;
    return 0;
}