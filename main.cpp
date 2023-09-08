#include <ncurses.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>


void interact_navigator(int&, const std::vector<std::string>& );
std::string stringify_directory_contents(const char* command = "ls -a");


std::vector<std::string> splitString(const std::string& inputString, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(inputString);
    std::string token;
    std::cout << token << ' ';
    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    initscr(); // Initialize ncurses

    cbreak(); 
    keypad(stdscr, TRUE); 

    //std::string folder_content = stringify_directory_contents();

    int current_option = 0;
    std::vector<std::string> options = {"option 1", "option 2"};

    // for (size_t i = 0; i> options.size(); i++) {
    //     std::cout << options[i] << ' ';
    // }
    
    interact_navigator(current_option, options);

    endwin(); // End ncurses
    return 0;
}

std::string stringify_directory_contents(const char* command) {
    char buffer[128]; 
    std::string result = "";

    FILE* pipe = popen(command, "r");
    if (!pipe) {
        printf("popen failed!");
        return result;
    }
    while (!feof(pipe)) {
        if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

void interact_navigator(int& current_option, const std::vector<std::string>& options) {
    int ch;

    while (1) {
        clear();
        printw("Use arrow keys to navigate. Press Enter to select an option.\n");

        for (int i = 0; i < 4; i++) {
            if (i == current_option) {
                attron(A_REVERSE);
            }
            printw("%s ", options[i].c_str());
            attroff(A_REVERSE);
        }

        ch = getch();
        switch (ch) {
            case KEY_LEFT:
                current_option = (current_option - 1 + 4) % 4;
                break;
            case KEY_RIGHT:
                current_option = (current_option + 1) % 4;
                break;
            case '\n':
                if (current_option == 3) {
                    return;
                }
                break;
        }
    }
    return;
}