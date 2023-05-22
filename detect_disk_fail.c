#include <stdio.h>
#include <stdlib.h>
#include <sys/statfs.h>

int main() {
    struct statfs fs;
    int result = statfs("/", &fs);  // check the root file system

    if (result == -1) {
        printf("Error: failed to get file system information\n");
        exit(1);
    }

    if (fs.f_blocks == 0) {
        printf("Error: disk failure detected\n");
        exit(1);
    }

    printf("Disk space: %ld bytes\n", fs.f_blocks * fs.f_bsize);

    return 0;
}
