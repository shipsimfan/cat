#include <los.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1025

int main(int argc, const char** argv) {
    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        exit(1);
    }

    uint64_t fd = open_file(argv[1]);
    if (fd == 0xFFFFFFFFFFFFFFFF) {
        printf("Error while opening file!\n");
        return -1;
    }

    char* buffer = (char*)malloc(BUFFER_SIZE);
    buffer[BUFFER_SIZE - 1] = 0;

    while (1) {
        uint64_t bytes_read = read_file(fd, (void*)buffer, BUFFER_SIZE - 1);
        if (bytes_read == 0xFFFFFFFFFFFFFFFF) {
            printf("Error while reading file!\n");
            return -1;
        }

        if (bytes_read == 0) {
            break;
        }

        printf("%s", buffer);
    }

    printf("\n");

    return 0;
}
