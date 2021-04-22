#include <stdio.h>
#include <time.h>

#define C_ROW_SIZE 100
#define C_COLUMN_SIZE 250
#define C_LOOP_COUNT 1000


int arr[C_ROW_SIZE][C_COLUMN_SIZE];

double getTime(double c) {
    return ((double) c) / CLOCKS_PER_SEC;
}

double subscriptOperations() {
    int val = 0;
    int a = 0;
    int b = 0;
    int counter = 0;
    clock_t start = clock();
    while (counter < C_LOOP_COUNT) {
        counter += 1;
        for (a = 0; a < C_ROW_SIZE; a++) {
            for(b = 0; b < C_COLUMN_SIZE; b++) {
                if (b%2 == 0) {
                    val += arr[a][b];
                } else {
                    val += arr[a][b] * 2;
                }
            }
        }
    }
    return getTime(clock() - start);
}

double pointerOperations() {
    int val = 0;
    int a = 0;
    int b = 0;
    int counter = 0;
    clock_t start = clock();
    while (counter < C_LOOP_COUNT) {
        counter += 1;
        for (a = 0; a < C_ROW_SIZE; a++) {
            for(b = 0; b < C_COLUMN_SIZE; b++) {
                if (b%2 == 0) {
                    val += *(*(arr+a)+b);
                } else {
                    val += *(*(arr+a)+b) * 2;
                }
            }
        }
    }
    return getTime(clock() - start);
}

int main()
{
    double subscriptTime = 0.0;
    double pointerTime = 0.0;
    int a = 0;
    int b = 0;
    for (a = 0; a < C_ROW_SIZE; a++) {
        for(b = 0; b < C_COLUMN_SIZE; b++) {
            arr[a][b] = a+b;
        }
    }
    
    subscriptTime += subscriptOperations();
    pointerTime += pointerOperations();
    
    for (a = 0; a < C_ROW_SIZE; a++) {
        for(b = 0; b < C_COLUMN_SIZE; b++) {
            arr[a][b] = b-a;
        }
    }
    pointerTime += pointerOperations();
    subscriptTime += subscriptOperations();
    printf("Subscript operations time - %f\n", subscriptTime);
    printf("Poniter operations time - %f\n", pointerTime);
    printf("********************\n");
    printf("Pointer operations performance - %f\n", ((subscriptTime-pointerTime)/subscriptTime)*100);
    return 0;
}

