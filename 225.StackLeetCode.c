


typedef struct {
    int vet[100];
    int topo;
    int base;
    int limite;
} MyStack;


MyStack* myStackCreate() {
    MyStack * p = NULL;
    p = (MyStack *)malloc(sizeof(MyStack));
    p->topo = 0;
    p->base = 0;
    p->limite = 100;
    return p;
}

void myStackPush(MyStack* obj, int x) {
    obj->vet[obj->topo] = x;
    obj->topo++;
}

int myStackPop(MyStack* obj) {
    int aux;
    aux = obj->vet[obj->topo-1];
    obj->topo--;
    return aux;
}

int myStackTop(MyStack* obj) {
    int x;
    x = obj->vet[obj->topo-1];
    return x;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->topo == obj->base) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
