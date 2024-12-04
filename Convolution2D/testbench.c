#include <stdio.h>
#include "convolution2D.h"

int main() {
    int rows = 5, cols = 5;

    int input[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int kernel[3][3] = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };

    int output[3][3] = {0};

    convolution2D(rows, cols, input, kernel, output);

    printf("Output Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}
