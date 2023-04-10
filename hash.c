#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MATRIX_SIZE 10

void matrix_to_string(int matrix[MATRIX_SIZE][MATRIX_SIZE], char* str) {
    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            sprintf(str, "%d", matrix[i][j]);
            str += strlen(str);
        }
    }
}

void sha256_hash(unsigned char hash[SHA256_DIGEST_LENGTH], char* str) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
}

void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                             {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                                             {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                                             {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
                                             {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
                                             {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
                                             {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
                                             {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
                                             {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
                                             {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};
    char str[MATRIX_SIZE * MATRIX_SIZE * 2 + 1];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    matrix_to_string(matrix, str);
    sha256_hash(hash, str);
    printf("SHA256 Hash: ");
    print_hash(hash);

    return 0;
}