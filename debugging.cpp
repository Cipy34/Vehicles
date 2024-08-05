//#include <cstdio>
//
//void processFile(const char* filename) {
//    FILE* file = fopen(filename, "r");
//    if (file == NULL) {
//        printf("File not found\n");
//        return;
//    }
//
//    char buffer[10];
//    while (fgets(buffer, 10, file)) { *
//        int number;
//        // Incorrect usage of sscanf, not handling return value properly
//        sscanf(buffer, "%d", number); *
//        printf("Read number: %d\n", number); *
//    }
//
//    fclose(file);
//}
//
//int main() {
//    processFile("numbers.txt");
//    return 0;
//}

#include <cstdio>

void processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    char buffer[10];
    while (fgets(buffer, sizeof(buffer), file)) { //
        int number;
        // Proper usage of sscanf with error checking
        if (sscanf(buffer, "%d", &number) == 1) { //
            printf("Read number: %d\n", number); //
        } else {
            printf("Failed to read number from buffer: %s\n", buffer); //
        }
    }

    fclose(file);
}

int main() {
    processFile("numbers.txt");
    return 0;
}
