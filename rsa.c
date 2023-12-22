#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;  // Not prime
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;  // Not prime
        }
    }

    return 1;  // Prime
}

void factorize_number(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }

    // If no prime factors found, print the number itself
    printf("%d=%d*%d\n", n, n, 1);
}

void factorize_file(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", file_path);
        exit(EXIT_FAILURE);
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        factorize_number(number);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* file_path = argv[1];
    factorize_file(file_path);

    return EXIT_SUCCESS;
}

