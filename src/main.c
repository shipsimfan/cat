#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1025

int main(int argc, const char** argv) {
    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error while opening %s\n", argv[1]);
        exit(1);
    }

    while (1) {
        int val = fgetc(file);

        if(val < 0) {
            if(feof(file)) {
                fflush(stdout);
                exit(0);
            }

            printf("Error while reading %s\n", argv[1]);
            exit(1);
        }

        printf("%c", val);
    }
}
