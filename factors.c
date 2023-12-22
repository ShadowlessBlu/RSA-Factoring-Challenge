#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize_number(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
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

