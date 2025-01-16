#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stos.h"

int main(void) {
    estos stack = NULL; // Inicjalizacja stosu
    char input[256];
    printf("Wprowadź wyrażenie w ONP:\n");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " \n");
    while (token != NULL) {
        if (isNumber(token)) {
            // Jeśli liczba, dodaj na stos
            push(&stack, atoi(token));
        } else {
            // Jeśli operator, wykonaj obliczenie
            calculate(&stack, token);
        }
        token = strtok(NULL, " \n");
    }
    if (!empty(stack)) {
        int result = pop(&stack);
        if (empty(stack)) {
            printf("Resault: %d\n", result);
        } else {
            printf("Error: Invalid ONP expression.\n");
        }
    }
}