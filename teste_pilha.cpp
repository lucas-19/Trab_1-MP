#include "pilha.hpp"
using namespace std;

bool testCreate() { //okS
    Stack* aux = NULL;
    aux = aux->create();    
    return true;
}

bool testPush() {
    
    bool status = false;
    try {
        ValueProps element;
        element.value = 10;
        Stack* aux = NULL;
        aux = aux->create();
        aux->push(aux, element);
        cout << aux->topReturn(aux)->value << endl;
        if (aux->topReturn(aux)->value == element.value) {
            status = true;
            
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
        }
    }
    catch(invalid_argument& ia) {
        cout << ia.what() << endl;
    }
    return status;
}


int main() {
    bool teste;
    teste = testCreate();
    cout << "testCreate: " << teste << endl;
    teste = testDestroy();
    cout << "testDestroy: " << teste << endl;
    teste = testPush();
    cout << "testPush: " << teste << endl;
    teste = testPop();
    cout << "testPop: " << teste << endl;
    teste = testTop();
    cout << "testTop: " << teste << endl;
    return 0;
}