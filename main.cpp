#include <dirent.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/stat.h> // For stat() function to determine if the entry is a directory

using namespace std;

bool has_cpp_extension(const string& filename) {
    const string extension = ".cpp";
    if (filename.length() >= extension.length()) {
        return (0 == filename.compare(filename.length() - extension.length(), extension.length(), extension));
    }
    return false;
}

void read_directory(const string& name, vector<string>& entries)
{
    DIR* dirp = opendir(name.c_str());
    if (dirp == NULL) {
        cerr << "Error opening directory: " << name << endl;
        return;
    }
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the entry
        string fullPath = name + "/" + dp->d_name;

        // Check if the entry is a directory
        struct stat statbuf;
        if (stat(fullPath.c_str(), &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            // Recursively read this directory
            read_directory(fullPath, entries);
        } else {
            // Check if the entry has a .cpp extension
            if (has_cpp_extension(dp->d_name)) {
                entries.push_back(fullPath);
            }
        }
    }
    closedir(dirp);
}

int main(){
    vector<string> entries;
    read_directory("D:\\facultate\\oop training\\Vehicles", entries);

    // Sort the entries alphabetically
    sort(entries.begin(), entries.end());

    // Print the sorted entries
    for (const string& entry : entries) {
        cout << entry << endl;
    }

    return 0;
}
