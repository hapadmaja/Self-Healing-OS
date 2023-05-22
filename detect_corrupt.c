#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int isFileCorrupted(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (file == NULL) {
        printf("Error: failed to open file %s\n", filePath);
        exit(1);
    }

    // Check if the file can be read successfully
    int result = fseek(file, 0, SEEK_SET);
    if (result != 0) {
        printf("File %s is corrupted\n", filePath);
        fclose(file);
        return 1;
    }

    // Check if the file has a valid size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == -1) {
        printf("File %s is corrupted\n", filePath);
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}

void detectCorruptedFiles(const char* directory) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Error: failed to open directory %s\n", directory);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and special files
        if (entry->d_type == DT_DIR || entry->d_type == DT_REG) {
            char filePath[256];
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);

            if (isFileCorrupted(filePath) == 0) {
                printf("File %s is not corrupted\n", filePath);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char* directory = "/path/to/directory";

    detectCorruptedFiles(directory);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int isFileCorrupted(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (file == NULL) {
        printf("Error: failed to open file %s\n", filePath);
        exit(1);
    }

    // Check if the file can be read successfully
    int result = fseek(file, 0, SEEK_SET);
    if (result != 0) {
        printf("File %s is corrupted\n", filePath);
        fclose(file);
        return 1;
    }

    // Check if the file has a valid size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == -1) {
        printf("File %s is corrupted\n", filePath);
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}

void detectCorruptedFiles(const char* directory) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Error: failed to open directory %s\n", directory);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and special files
        if (entry->d_type == DT_DIR || entry->d_type == DT_REG) {
            char filePath[256];
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);

            if (isFileCorrupted(filePath) == 0) {
                printf("File %s is not corrupted\n", filePath);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char* directory = "/path/to/directory";

    detectCorruptedFiles(directory);

    return 0;
}
