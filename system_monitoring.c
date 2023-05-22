#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
    // Check CPU usage
    FILE* cpuFile = fopen("/proc/stat", "r");
    if (cpuFile == NULL) {
        printf("Error: failed to open CPU stats file\n");
        exit(1);
    }
    
    char cpuName[20];
    unsigned long long user, nice, system, idle;
    int result = fscanf(cpuFile, "%s %llu %llu %llu %llu", cpuName, &user, &nice, &system, &idle);
    fclose(cpuFile);
    
    if (result != 5) {
        printf("Error: failed to read CPU stats\n");
        exit(1);
    }
    
    unsigned long long total = user + nice + system + idle;
    float cpuUsage = 100.0 * (total - idle) / total;
    printf("CPU usage: %.2f%%\n", cpuUsage);
    
    // Check memory usage
    struct sysinfo memInfo;
    if (sysinfo(&memInfo) == -1) {
        printf("Error: failed to get memory info\n");
        exit(1);
    }
    
    unsigned long long totalRAM = memInfo.totalram * memInfo.mem_unit;
    unsigned long long usedRAM = (memInfo.totalram - memInfo.freeram) * memInfo.mem_unit;
    float memUsage = 100.0 * usedRAM / totalRAM;
    printf("Memory usage: %.2f%%\n", memUsage);
    
    // Check disk space
    FILE* diskFile = popen("df -h /", "r");
    if (diskFile == NULL) {
        printf("Error: failed to execute disk space command\n");
        exit(1);
    }
    
    char line[256];
    if (fgets(line, sizeof(line), diskFile) == NULL) {
        printf("Error: failed to read disk space\n");
        exit(1);
    }
    
    unsigned long long totalDisk, usedDisk;
    sscanf(line, "%*s %*s %llu %llu", &totalDisk, &usedDisk);
    float diskUsage = 100.0 * usedDisk / totalDisk;
    printf("Disk usage: %.2f%%\n", diskUsage);
    
    pclose(diskFile);
    
    // Check network connectivity
    int networkResult = system("ping -c 1 google.com >/dev/null");
    if (networkResult == -1) {
        printf("Error: failed to execute network command\n");
        exit(1);
    }
    
    if (networkResult == 0) {
        printf("Network connectivity: OK\n");
    } else {
        printf("Network connectivity: Failed\n");
    }
    
    return 0;
}
