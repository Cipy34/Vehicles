#include <dirent.h>
#include <string>
#include <iostream>

using namespace std;

void read_directory(const string& name)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        cout<<dp->d_name<<endl;
    }
    closedir(dirp);
}

int main(){
    read_directory(".");
}
