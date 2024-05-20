#include <stdio.h>

#define SIZE 10

void myAlgol(int n[], int size);
void myAlgo2(int n[], int size);

int main() {
    int myNumber1[SIZE] = {22, 5, 67, 98, 45, 32, 101, 99, 73, 10};
    int myNumber2[SIZE] = {22, 5, 67, 98, 45, 32, 101, 99, 73, 10};

    myAlgol(myNumber1, SIZE);
    printf("\n\n");
    myAlgo2(myNumber2, SIZE);

    return 0;
}

void myAlgol(int n[], int size) {
    int i, j, min, minidx, temp;

    for (i = 0; i < size - 1; i++) {
        min = n[i];
        minidx = i;

        for (j = i + 1; j < size; j++) {
            if (n[j] < min) {
                min = n[j];
                minidx = j;
            }
        }

        if (min < n[i]) {
            temp = n[i];
            n[i] = min;
            n[minidx] = temp;

            printf("\nSequence %d: ", i + 1);
            for (int k = 0; k < size; k++) {
                printf("%d ", n[k]);
            }
        }
    }
}

void myAlgo2(int n[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (n[j] > n[j + 1]) {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }

        printf("\nSequence %d: ", i + 1);
        for (int k = 0; k < size; k++) {
            printf("%d ", n[k]);
        }
    }
}
