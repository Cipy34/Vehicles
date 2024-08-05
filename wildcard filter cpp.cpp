#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <algorithm>

bool hasExtension(const std::string& filename, const std::string& extension) {
    if (filename.length() >= extension.length()) {
        return (0 == filename.compare(filename.length() - extension.length(), extension.length(), extension));
    } else {
        return false;
    }
}

void traverseAndFilterDirectory(const std::string& dirPath, const std::string& extension) {
    DIR* dir = opendir(dirPath.c_str());
    if (dir == NULL) {
        std::cerr << "Error opening directory: " << dirPath << std::endl;
        return;
    }

    struct dirent* entry;
    std::vector<std::string> filteredFiles;
    while ((entry = readdir(dir)) != NULL) {
        std::string entryName = entry->d_name;
        if (entryName == "." || entryName == "..") {
            continue;
        }

        std::string fullPath = dirPath + "/" + entryName;

        struct stat fileStat;
        if (stat(fullPath.c_str(), &fileStat) < 0) {
            std::cerr << "Error getting file attributes for: " << fullPath << std::endl;
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            traverseAndFilterDirectory(fullPath, extension);
        } else if (hasExtension(entryName, extension)) {
            filteredFiles.push_back(fullPath);
        }
    }

    closedir(dir);

    // Sort filtered files
    std::sort(filteredFiles.begin(), filteredFiles.end());

    // Print filtered and sorted files
    for (const auto& file : filteredFiles) {
        std::cout << file << std::endl;
    }
}

int main() {
    const std::string dirPath = "."; // Current directory
    const std::string extension = ".cpp"; // Filter for .cpp files
    traverseAndFilterDirectory(dirPath, extension);
    return 0;
}
