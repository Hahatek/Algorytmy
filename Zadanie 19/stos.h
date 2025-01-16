#ifndef STOS_H
#define STOS_H

typedef struct stos {
    int key;
    struct stos* next;
}stos;
typedef stos* estos;


int push(estos* top, int number);
int pop(estos* top);
int peek(estos top);
int empty(estos top);

void calculate(estos* stack, const char* operator);
int isNumber(const char* token);

#endif //STOS_H
