#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "voiceRecognition.h"
#include "numberConverter.h"

using namespace std;

class Calendar {
private:
    string events[100]; // Array to store events
    string dates[100];  // Array to store event dates
    int eventCount;     // Number of events currently in the calendar
    SpeechAssistant assistant;

public:
    Calendar() : eventCount(0) {}

    void addEvent(const string& date, const string& event) {
        if (eventCount < 100) {
            dates[eventCount] = date;
            events[eventCount] = event;
            eventCount++;
            cout << "Event added successfully." << endl;
            assistant.speak("Event added successfully.");
        } else {
            cout << "Calendar is full. Cannot add more events." << endl;
            assistant.speak("Calendar is full. Cannot add more events.");
        }
    }

    void viewEvents() {
        if (eventCount == 0) {
            cout << "No events in the calendar." << endl;
            assistant.speak("No events in the calendar.");
            return;
        }

        for (int i = 0; i < eventCount; ++i) {
            assistant.speak("Following are the events in the calendar.");
            cout << dates[i] << ": " << events[i] << endl;
        }
    }

    void removeEvent(const string& date) {
        bool found = false;
        for (int i = 0; i < eventCount; ++i) {
            if (dates[i] == date) {
                found = true;
                for (int j = i; j < eventCount - 1; ++j) {
                    dates[j] = dates[j + 1];
                    events[j] = events[j + 1];
                }
                eventCount--;
                cout << "Event on " << date << " removed successfully." << endl;
                assistant.speak("Event on " + date + " removed successfully.");
                break;
            }
        }
        if (!found) {
            cout << "No event found on " << date << "." << endl;
            assistant.speak("No event found on " + date);
        }
    }

    void findEvent(const string& date) {
        bool found = false;
        for (int i = 0; i < eventCount; ++i) {
            if (dates[i] == date) {
                found = true;
                cout << "Event on " << date << ": " << events[i] << endl;
                assistant.speak("Event on " + date + ": " + events[i]);
                break;
            }
        }
        if (!found) {
            cout << "No event found on " << date << "." << endl;
            assistant.speak("No event found on " + date);
        }
    }

    void calendarMenu() {
        while (true) {
            system("cls");
            cout << "1. Add Event" << endl;
            cout << "2. View Events" << endl;
            cout << "3. Remove Event" << endl;
            cout << "4. Find Event" << endl;
            cout << "5. Back to Main Menu" << endl;

            string message = "What would you like to do? Speak out the name of option to proceed.";
            cout << message << endl;
            assistant.speak(message);
            string choice = assistant.run();
            
            system("cls");

            char option;

            if(choice == "Add Event") {
                option = '1';
            } else if(choice == "View Events") {
                option = '2';
            } else if(choice == "Remove Event") {
                option = '3';
            } else if(choice == "Find Event") {
                option = '4';
            } else if(choice == "Back to Main Menu") {
                option = '5';
            } else {
                option = '0';
            }

            switch (option) {
                case '1': {
                    string date, event;
                    string year, month, day;
                    cout << "Speak the year of the event: ";
                    assistant.speak("Speak the year of the event");
                    year = assistant.run();

                    cout << "Speak the month of the event: ";
                    assistant.speak("Speak the month of the event");
                    month = assistant.run();

                    cout << "Speak the day of the event: ";
                    assistant.speak("Speak the day of the event");
                    day = assistant.run();

                    date = year + "-" + month + "-" + day;
                    cout << "Event date: " << date << endl;

                    cout << "Speak the event description: ";
                    assistant.speak("Speak the event description");
                    event = assistant.run();
                    
                    cout << "Event description: " << event << endl;
                    
                    addEvent(date, event);
                    break;
                }
                case '2':
                    viewEvents();
                    break;
                case '3': {
                    string date, year, month, day;

                    cout << "Speak the year of the event: ";
                    assistant.speak("Speak the year of the event");
                    year = assistant.run();

                    cout << "Speak the month of the event: ";
                    assistant.speak("Speak the month of the event");
                    month = assistant.run();

                    cout << "Speak the day of the event: ";
                    assistant.speak("Speak the day of the event");
                    day = assistant.run();

                    date = year + "-" + month + "-" + day;
                    cout << "Event date: " << date << endl;

                    removeEvent(date);
                    break;
                }
                case '4': {
                    string date, year, month, day;

                    cout << "Speak the year of the event: ";
                    assistant.speak("Speak the year of the event");
                    year = assistant.run();

                    cout << "Speak the month of the event: ";
                    assistant.speak("Speak the month of the event");
                    month = assistant.run();

                    cout << "Speak the day of the event: ";
                    assistant.speak("Speak the day of the event");
                    day = assistant.run();

                    date = year + "-" + month + "-" + day;
                    cout << "Event date: " << date << endl;

                    findEvent(date);
                    break;
                }
                case '5':
                    assistant.speak("Returning to main menu");
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
