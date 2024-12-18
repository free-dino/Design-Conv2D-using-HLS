#include "convolution2D.h"
#include <stdio.h>

void convolution2D(int input[5][5], int kernel[3][3], int output[3][3]) {
	#pragma HLS INTERFACE s_axilite port=return bundle=conv_io
	#pragma HLS INTERFACE s_axilite port=output bundle=conv_io
	#pragma HLS INTERFACE s_axilite port=kernel bundle=conv_io
	#pragma HLS INTERFACE s_axilite port=input bundle=conv_io
	#pragma HLS INLINE
    #pragma HLS ARRAY_PARTITION variable=input block dim=2 factor=3
    #pragma HLS ARRAY_PARTITION variable=kernel complete dim=0

    for (int i = 0; i < 3; i++) {
	#pragma HLS PIPELINE II=1
        for (int j = 0; j < 3; j++) {
	#pragma HLS PIPELINE II=1
            int sum = 0;
            for (int ki = 0; ki < 3; ki++) {
			#pragma HLS PIPELINE II=1
                for (int kj = 0; kj < 3; kj++) {
                    #pragma HLS UNROLL
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
}
