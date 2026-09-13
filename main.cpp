#include <iostream>
#include <conio.h>

#include "menu.h"
#include "clock.h"
#include "notepad.h"
#include "calender.h"
#include "calculator.h"
#include "voiceRecognition.h"
#include "numberConverter.h"

using namespace std;

int main() {
    Menu menu;
    menu.setcursor(0, 0);
    Clock clock;
    Notepad notepad;
    Calendar calendar;
    Calculator calculator;
    SpeechAssistant assistant;

    while (true) {
        menu.display_menu();

        assistant.speak("What would you like to do? Speak out the name of option to proceed.");
        string choice = assistant.run();

        system("cls");  // Clear the screen before displaying the selected option

        if (choice == "clock") {
            clock.clock_menu();
        } else if (choice == "calculator") {
            calculator.calculatorMenu();
        } else if (choice == "notepad") {
            notepad.notepad_menu();
        } else if (choice == "calendar") {
            calendar.calendarMenu();
        } else if (choice == "exit") {
            assistant.quit();
            break;
        } else {
            assistant.unknownCommand();
        }

        cout << "\nPress any key to return to the menu...";
        _getch();
    }

    return 0;
}
