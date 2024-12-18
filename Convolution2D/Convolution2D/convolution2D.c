#include "convolution2D.h"
#include <stdio.h>

void convolution2D(int input[5][5], int kernel[3][3], int output[3][3]) {
    #pragma HLS ARRAY_PARTITION variable=input block dim=2 factor=3
    #pragma HLS ARRAY_PARTITION variable=kernel complete dim=0

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int ki = 0; ki < 3; ki++) {
                #pragma HLS UNROLL
                for (int kj = 0; kj < 3; kj++) {
                    #pragma HLS UNROLL
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
}
