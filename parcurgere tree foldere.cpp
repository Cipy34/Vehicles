#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string>

void traverseDirectory(const std::string& dirPath) {
    DIR* dir = opendir(dirPath.c_str());
    if (dir == NULL) {
        std::cerr << "Error opening directory: " << dirPath << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string entryName = entry->d_name;
        if (entryName == "." || entryName == "..") {
            continue;
        }

        std::string fullPath = dirPath + "/" + entryName;
        std::cout << "Path: " << fullPath << std::endl;

        struct stat fileStat;
        if (stat(fullPath.c_str(), &fileStat) < 0) {
            std::cerr << "Error getting file attributes for: " << fullPath << std::endl;
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            traverseDirectory(fullPath);
        }
    }

    closedir(dir);
}

int main() {
    const std::string dirPath = "."; // Current directory
    traverseDirectory(dirPath);
    return 0;
}
