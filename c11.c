#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>  // Include OpenMP header

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 1000; // Number of random 4-digit numbers
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random 4-digit numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9000 + 1000;
    }

    // Record start time using OpenMP
    double start = omp_get_wtime();

    // Perform bubble sort
    bubbleSort(arr, n);

    // Record end time using OpenMP
    double end = omp_get_wtime();

    // Calculate elapsed time
    double time_spent = end - start;

    printf("Bubble sort of %d random 4-digit numbers took %f seconds.\n", n, time_spent);

    free(arr);
    return 0;
}
