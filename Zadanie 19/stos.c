#include "stos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int push(estos* top, int number) {

    estos new_element = malloc(sizeof(stos));
    new_element->key = number;
    new_element->next = *top;
    *top = new_element;

    return 1;
}

int pop(estos* top) {
    if (*top == NULL) {
        printf("Stos jest pusty \n");
        return 0;
    }

    estos temp_element = *top;
    int value = temp_element->key;
    *top = temp_element->next;
    free(temp_element);
    return value;

}

int peek(estos top) {
    if (top == NULL) {
        printf("Stos jest pusty \n");
        return 0;
    }

    return top->key;
}

int empty(estos top) {
    return top == NULL;
}

// sprawdza czy liczba
int isNumber(const char* token) { // uzywamy const aby ta funckja nie zmienila nam wartosci
    if (token == NULL) {
        return 0;
    }
        if (*token == '-' && isdigit(*(token + 1))) {
            token++;
        } // Ujemne liczby
    while (*token) {
        if (!isdigit(*token)) { // dziala kiedy token nie jest liczba
            return 0;
        }
        token++;
    }
    return 1;
}

//  operacje arytmetyczne
void calculate(estos* stack, const char* operator) {
    int b, a;
    if (strcmp(operator, "neg") == 0) {
        b = pop(stack);
        push(stack, -b);
    } else {
        b = pop(stack);
        a = pop(stack);
        if (strcmp(operator, "+") == 0) {
            push(stack, a + b);
        } else if (strcmp(operator, "-") == 0) {
            push(stack, a - b);
        } else if (strcmp(operator, "*") == 0) {
            push(stack, a * b);
        } else if (strcmp(operator, "/") == 0) {
            if (b == 0) {
                printf("Error: Dividing by zero.\n");
                exit(1);
            }
            push(stack, a / b);
        } else {
            printf("Error: Unknown operator %s.\n", operator);
            exit(1);
        }
    }
}