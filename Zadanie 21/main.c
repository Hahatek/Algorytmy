#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("\n=== Algorithm Sorting Comparison ===\n");
    printf("1. Run full comparison test\n");
    printf("2. Exit\n");
}

void runFullTest(int N, int M, FILE* output) {
    sort* bubbleMeasurements = (sort*)calloc(M, sizeof(sort));
    sort* insertMeasurements = (sort*)calloc(M, sizeof(sort));
    sort* shellMeasurements = (sort*)calloc(M, sizeof(sort));
    sort* quickMeasurements = (sort*)calloc(M, sizeof(sort));

    printf("\nRunning full comparison test (%d iterations)...\n", M);
    fprintf(output, "\n=== Full Test Results (N=%d, M=%d) ===\n", N, M);

    for(int i = 0; i < M; i++) {
        // Generate random array
        int* arr = (int*)malloc(N * sizeof(int));
        for(int j = 0; j < N; j++) {
            arr[j] = randomNumber(0, 1000);
        }
        int* testArr = (int*)malloc(N * sizeof(int));

        copy(testArr, arr, N);
        bubbleSort(testArr, N, &bubbleMeasurements[i]);

        copy(testArr, arr, N);
        byInsertingSort(testArr, N, &insertMeasurements[i]);

        copy(testArr, arr, N);
        shellSort(testArr, N, &shellMeasurements[i]);

        copy(testArr, arr, N);
        quickSort(testArr, 0, N-1, &quickMeasurements[i]);

        free(arr);
        free(testArr);

        // Show progress
        if((i + 1) % (M/10) == 0) {
            printf("Progress: %d%%\n", (i + 1) * 100 / M);
        }
    }

    fprintf(output, "\nBubble Sort Results:\n");
    printf("\nBubble Sort Results:\n");
    showData(bubbleMeasurements, M, output);

    fprintf(output, "\nInsertion Sort Results:\n");
    printf( "\nInsertion Sort Results:\n");
    showData(insertMeasurements, M, output);

    fprintf(output, "\nShell Sort Results:\n");
    printf("\nShell Sort Results:\n");
    showData(shellMeasurements, M, output);

    fprintf(output, "\nQuick Sort Results:\n");
    printf( "\nQuick Sort Results:\n");
    showData(quickMeasurements, M, output);

    free(bubbleMeasurements);
    free(insertMeasurements);
    free(shellMeasurements);
    free(quickMeasurements);
}

int main() {
    srand(time(NULL));
    int N = 1000;
    int M = 1000;
    int choice, algorithm;
    FILE* output = fopen("results.txt", "w");

    if(output == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                runFullTest(N, M, output);
                break;
            case 2:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while(choice != 2);

    fclose(output);
    return 0;
}