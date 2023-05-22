#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs fs;
    int result = statvfs("/", &fs);  // check the root file system

    if (result == -1) {
        printf("Error: failed to get file system information\n");
        exit(1);
    }

    if (fs.f_blocks == 0) {
        printf("Error: disk failure detected\n");
        exit(1);
    }

    printf("Disk space: %ld bytes\n", fs.f_blocks * fs.f_frsize);

    return 0;
}
