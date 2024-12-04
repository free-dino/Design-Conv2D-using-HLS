#include "convolution2D.h"
#include <stdio.h>

void convolution2D(int rows, int cols, int input[rows][cols], int kernel[3][3], int output[rows-2][cols-2]) {
	for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols - 2; j++) {
            int sum = 0;
            for (int ki = 0; ki < 3; ki++) {
                for (int kj = 0; kj < 3; kj++) {
                    int product = input[i + ki][j + kj] * kernel[ki][kj];
                    sum += product;
                }
            }
            output[i][j] = sum;
        }
    }
}
