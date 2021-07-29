#include <los.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1025

int main(int argc, const char** argv) {
    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        exit(1);
    }

    int64_t fd = open_file(argv[1], OPEN_READ);
    if (fd < 0) {
        printf("Error while opening file: %s\n", strerror(fd));
        exit(1);
    }

    char* buffer = (char*)malloc(BUFFER_SIZE);
    buffer[BUFFER_SIZE - 1] = 0;

    while (1) {
        int64_t bytes_read = read_file(fd, (void*)buffer, BUFFER_SIZE - 1);
        if (bytes_read < -1) {
            printf("Error while reading file: %s\n", strerror(bytes_read));
            exit(1);
        }

        if (bytes_read == -1)
            break;

        printf("%s", buffer);
    }

    printf("\n");

    return 0;
}
