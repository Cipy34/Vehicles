//windows

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void printFileAttributes(const char* path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0) {
        std::cerr << "Error getting file attributes for: " << path << std::endl;
        return;
    }

    std::cout << "File: " << path << std::endl;
    std::cout << "Size: " << fileStat.st_size << " bytes" << std::endl;
    std::cout << "Permissions: ";
    std::cout << ((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    std::cout << ((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    std::cout << ((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    std::cout << ((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    std::cout << ((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    std::cout << ((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    std::cout << ((fileStat.st_mode & S_IROTH) ? "r" : "-");
    std::cout << ((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    std::cout << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    std::cout << std::endl;
}

void listFilesInDirectory(const char* dirPath) {
    DIR* dir = opendir(dirPath);
    if (dir == NULL) {
        std::cerr << "Error opening directory: " << dirPath << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string filePath = std::string(dirPath) + "/" + entry->d_name;
        printFileAttributes(filePath.c_str());
    }

    closedir(dir);
}

int main() {
    const char* dirPath = "."; // Current directory
    listFilesInDirectory(dirPath);
    return 0;
}

//linux
////
//#include <iostream>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
//#include <dirent.h>
//#include <pwd.h>
//#include <grp.h>
//
//void printFileAttributes(const char* path) {
//    struct stat fileStat;
//    if(stat(path, &fileStat) < 0) {
//        std::cerr << "Error getting file attributes for: " << path << std::endl;
//        return;
//    }
//
//    std::cout << "File: " << path << std::endl;
//    std::cout << "Size: " << fileStat.st_size << " bytes" << std::endl;
//    std::cout << "Owner: " << getpwuid(fileStat.st_uid)->pw_name << std::endl;
//    std::cout << "Group: " << getgrgid(fileStat.st_gid)->gr_name << std::endl;
//    std::cout << "Permissions: ";
//    std::cout << ((fileStat.st_mode & S_IRUSR) ? "r" : "-");
//    std::cout << ((fileStat.st_mode & S_IWUSR) ? "w" : "-");
//    std::cout << ((fileStat.st_mode & S_IXUSR) ? "x" : "-");
//    std::cout << ((fileStat.st_mode & S_IRGRP) ? "r" : "-");
//    std::cout << ((fileStat.st_mode & S_IWGRP) ? "w" : "-");
//    std::cout << ((fileStat.st_mode & S_IXGRP) ? "x" : "-");
//    std::cout << ((fileStat.st_mode & S_IROTH) ? "r" : "-");
//    std::cout << ((fileStat.st_mode & S_IWOTH) ? "w" : "-");
//    std::cout << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
//    std::cout << std::endl;
//}
//
//void listFilesInDirectory(const char* dirPath) {
//    DIR* dir = opendir(dirPath);
//    if (dir == NULL) {
//        std::cerr << "Error opening directory: " << dirPath << std::endl;
//        return;
//    }
//
//    struct dirent* entry;
//    while ((entry = readdir(dir)) != NULL) {
//        std::string filePath = std::string(dirPath) + "/" + entry->d_name;
//        printFileAttributes(filePath.c_str());
//    }
//
//    closedir(dir);
//}
//
//int main() {
//    const char* dirPath = "."; // Current directory
//    listFilesInDirectory(dirPath);
//    return 0;
//}

