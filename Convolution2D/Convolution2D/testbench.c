#include <stdio.h>
#include "convolution2D.h"

// Test 1: A simple kernel
void test_case_1() {
    int rows = 5, cols = 5;
    int input[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int kernel[3][3] = {
        {1, 1, 1},
        {1, -4, 1},
        {1, 1, 2}
    };

    int output[3][3] = {0};

    convolution2D(rows, cols, input, kernel, output);

    int expected_output[3][3] = {
        {41, 46, 51},
        {66, 71, 76},
        {91, 96, 101}
    };

    int pass = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (output[i][j] != expected_output[i][j]) {
                pass = 0;
                break;
            }
        }
    }

    if (pass) {
        printf("Test Case 1: PASS\n");
    } else {
        printf("Test Case 1: FAIL\n");
    }
}

// Test 2: A kernel containing negative values
void test_case_2() {
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

    int expected_output[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int pass = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (output[i][j] != expected_output[i][j]) {
                pass = 0;
                break;
            }
        }
    }

    if (pass) {
        printf("Test Case 2: PASS\n");
    } else {
        printf("Test Case 2: FAIL\n");
    }
}

// Test 3: A simple kernel (all elements are 1)
void test_case_3() {
    int rows = 5, cols = 5;
    int input[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int kernel[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int output[3][3] = {0};

    convolution2D(rows, cols, input, kernel, output);

    int expected_output[3][3] = {
        {63, 72, 81},
        {108, 117, 126},
        {153, 162, 171}
    };

    int pass = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (output[i][j] != expected_output[i][j]) {
                pass = 0;
                break;
            }
        }
    }

    if (pass) {
        printf("Test Case 3: PASS\n");
    } else {
        printf("Test Case 3: FAIL\n");
    }
}

// Test 4: A kernel containing both negative and positive values
void test_case_4() {
    int rows = 5, cols = 5;
    int input[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int kernel[3][3] = {
        {1, -1, 1},
        {-1, 4, -1},
        {1, -1, 1}
    };

    int output[3][3] = {0};

    convolution2D(rows, cols, input, kernel, output);

    int expected_output[3][3] = {
        {28, 32, 36},
        {48, 52, 56},
        {68, 72, 76}
    };

    int pass = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (output[i][j] != expected_output[i][j]) {
                pass = 0;
                break;
            }
        }
    }

    if (pass) {
        printf("Test Case 4: PASS\n");
    } else {
        printf("Test Case 4: FAIL\n");
    }
}

// Test 5: An input matrix containing negative values
void test_case_5() {
    int rows = 5, cols = 5;
    int input[5][5] = {
        {-1, -2, -3, -4, -5},
        {-6, -7, -8, -9, -10},
        {-11, -12, -13, -14, -15},
        {-16, -17, -18, -19, -20},
        {-21, -22, -23, -24, -25}
    };

    int kernel[3][3] = {
        {1, 1, 1},
        {1, -4, 1},
        {1, 1, 2}
    };

    int output[3][3] = {0};

    convolution2D(rows, cols, input, kernel, output);

    int expected_output[3][3] = {
        {-41, -46, -51},
        {-66, -71, -76},
        {-91, -96, -101}
    };

    int pass = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (output[i][j] != expected_output[i][j]) {
                pass = 0;
                break;
            }
        }
    }

    if (pass) {
        printf("Test Case 5: PASS\n");
    } else {
        printf("Test Case 5: FAIL\n");
    }
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
