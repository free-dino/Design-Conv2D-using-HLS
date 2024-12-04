#ifndef CONVOLUTION2D_H
#define CONVOLUTION2D_H

void convolution2D(int rows, int cols, int input[rows][cols], int kernel[3][3], int output[rows-2][cols-2]);

#endif
