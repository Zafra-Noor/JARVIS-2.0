#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

#include "voiceRecognition.h"

using namespace std;

class Notepad {
    private:
        SpeechAssistant assistant;
    public:
        void create_note() {
            string filename;

            assistant.speak("Speak the filename for the note.");
            cout << "Speak the filename for the note: ";
            filename = assistant.run();
            
            ofstream file(filename.c_str());

            if (file.is_open()) {

                string choice;
                cout << "Do you want to write the note or speak it ?";
                cout << "Enter 'w' to write or 's' to speak: ";
                cin >> choice;

                string note;
                if (choice == "w") {
                    cout << "Enter the note (Press Ctrl+Z to save and exit):" << endl;
                    cin.ignore();
                    while (getline(cin, note)) {
                        file << note << endl;
                    }
                } else if (choice == "s") {
                    assistant.speak("Speak the note you want to save.");
                    note = assistant.run();
                    file << note;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                    return;
                }
                file.close();
                cout << "Note saved successfully." << endl;
                assistant.speak("Note saved successfully.");
            } else {
                cout << "Error creating note." << endl;
                assistant.speak("Error creating note.");
            }

            // Ask the user if they want to close the Notepad window
            cout << "Do you want to close the Notepad window? Press 'y' to close or any other key to continue:";
            assistant.speak("Do you want to close the Notepad window? Press 'y' to close or any other key to continue.");

            char choice;
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                exit(0);
            }
        }

        void view_note() {
            string filename;
            
            assistant.speak("Enter the filename of the note you want to view.");
            cout << "Enter the filename of the note you want to view: ";
            filename = assistant.run();
            
            ifstream file(filename.c_str());

            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                assistant.speak("Error opening note. Please try again.");
                cout << "Error opening note. Please try again." << endl;
            }
        }

        void delete_note() {
            string filename;
            
            assistant.speak("Enter the filename of the note you want to delete.");
            cout << "Enter the filename of the note you want to delete: ";
            filename = assistant.run();

            if (remove(filename.c_str()) == 0) {
                cout << "Note deleted successfully." << endl;
                assistant.speak("Note deleted successfully.");
            } else {
                cout << "Error deleting note." << endl;
                assistant.speak("Error deleting note.");
            }
        }

        void notepad_menu() {
            while (true) {
                system("cls");
                cout << "1. Create a Note" << endl;
                cout << "2. View a Note" << endl;
                cout << "3. Delete a Note" << endl;
                cout << "4. Back to Main Menu" << endl;
                cout << "5. Quit Notepad" << endl;
                
                assistant.speak("What would you like to do in the Notepad? Speak out the option number to proceed.");
                cout << "What would you like to do in the Notepad? Enter the option number to proceed: ";
                
                string choice = assistant.run();

                char option;

                if (choice == "create") {
                    option = '1';
                } else if (choice == "view") {
                    option = '2';
                } else if (choice == "delete") {
                    option = '3';
                } else if (choice == "back") {
                    option = '4';
                } else if (choice == "quit") {
                    option = '5';
                } else {
                    option = choice[0];
                }

                system("cls");

                switch (option) {
                    case '1':
                        create_note();
                        break;
                    case '2':
                        view_note();
                        break;
                    case '3':
                        delete_note();
                        break;
                    case '4':
                        return;
                    case '5':
                        assistant.speak("Returning to the main menu.");
                        return;
                    default:
                        assistant.unknownCommand();
                        break;
                }

                cout << "\nPress any key to continue...";
                _getch();
            }
        }
};

#endif