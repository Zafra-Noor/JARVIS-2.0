#include <iostream>
#include <conio.h>
#include <windows.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

class Menu {
    public:
        void gotoxy(int x, int y) {
            CursorPosition.X = x;
            CursorPosition.Y = y;
            SetConsoleCursorPosition(console, CursorPosition);
        }

        void setcursor(bool visible, DWORD size) {
            if (size == 0)
                size = 20;

            CONSOLE_CURSOR_INFO lpCursor;
            lpCursor.bVisible = visible;
            lpCursor.dwSize = size;
            SetConsoleCursorInfo(console, &lpCursor);
        }

        void display_menu() {
            system("cls");
            int yPos = 0;

            while (yPos < SCREEN_HEIGHT - 3) {
                system("cls");
                for (int i = 0; i < yPos; ++i) {
                    cout << endl;
                }
                gotoxy(80, yPos);  // Adjusted x-position to center the text better
                cout << "Personal Assistant" << endl;

                yPos++;
                Sleep(50);
            }

            gotoxy(10, 2);  // Adjust the position of the menu
            cout << "1. Clock" << endl;
            gotoxy(10, 4);
            cout << "2. Calculator" << endl;
            gotoxy(10, 6);
            cout << "3. Notepad" << endl;
            gotoxy(10, 8);
            cout << "4. Calendar" << endl;
            gotoxy(10, 10);
            cout << "5. Exit" << endl;
            gotoxy(10, 12);
            cout << "What would you like to do? Speak out the name of option to proceed." << endl;
        }

};
