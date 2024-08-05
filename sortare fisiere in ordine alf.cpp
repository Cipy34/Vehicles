#include <iostream>
#include <vector>
#include <algorithm>
#include <dirent.h>

void listAndSortFiles(const char* dirPath) {
    DIR* dir = opendir(dirPath);
    if (dir == NULL) {
        std::cerr << "Error opening directory: " << dirPath << std::endl;
        return;
    }

    struct dirent* entry;
    std::vector<std::string> filenames;
    while ((entry = readdir(dir)) != NULL) {
        std::string entryName = entry->d_name;
        if (entryName != "." && entryName != "..") {
            filenames.push_back(entryName);
        }
    }

    closedir(dir);

    // Sort filenames
    std::sort(filenames.begin(), filenames.end());

    // Print sorted filenames
    for (const auto& filename : filenames) {
        std::cout << filename << std::endl;
    }
}

int main() {
    const char* dirPath = "."; // Current directory
    listAndSortFiles(dirPath);
    return 0;
}
