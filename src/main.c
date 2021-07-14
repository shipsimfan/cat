#include <los.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("CAT\n");

    uint64_t fd = open_file("1:/TEST.TXT");
    if (fd == 0xFFFFFFFFFFFFFFFF) {
        printf("Error while opening file!\n");
        return -1;
    }

    char* buffer = (char*)malloc(sizeof(char) * 32);
    for (int i = 0; i < 32; i++)
        buffer[i] = 0;

    uint64_t bytes_read = read_file(fd, (void*)buffer, 32);
    if (bytes_read == 0xFFFFFFFFFFFFFFFF) {
        printf("Error while reading file!\n");
        return -1;
    }

    printf("Message: %s\n", buffer);

    return 0xBADC0DE;
}
