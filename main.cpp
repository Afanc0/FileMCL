#include <ncurses.h>

void interact_navigator(int&, const char*[]);

int main() {
    initscr(); // Initialize ncurses

    cbreak(); 
    keypad(stdscr, TRUE); 

    int current_option = 0;
    const char* options[] = {"Option 1", "Option 2", "Option 3", "Quit"};

    interact_navigator(current_option, options);

    endwin(); // End ncurses
    return 0;
}


void interact_navigator(int& current_option, const char* options[]) {
    int ch;
    while (1) {
        clear();
        printw("Use arrow keys to navigate. Press Enter to select an option.\n");

        for (int i = 0; i < 4; i++) {
            if (i == current_option) {
                attron(A_REVERSE);
            }
            printw("%s ", options[i]);
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