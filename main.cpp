#include <iostream>
#include <cstdlib> 
#include <string>

bool list_directory_content(const std::string& directory = "./") {
    std::string command = "ls -a " + directory;
    return system(command.c_str());
}

int main(int argc, char *argv[]) {
    list_directory_content();
}