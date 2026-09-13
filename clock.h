#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>

#include "voiceRecognition.h"
#include "numberConverter.h"

class Clock {
    private:
        SpeechAssistant assistant;
    public:
        void showtime() {
            string message = "The current time is: ";
            message += __TIME__;
            cout << message << endl;
            assistant.speak(message);
        }

        void start_timer(int seconds) {
            bool paused = false; // Pause state variable
            while (seconds >= 0) {
                if (!paused) { // Check if the timer is not paused
                    system("cls");
                    int minutes = seconds / 60;
                    int secs = seconds % 60;
                    cout << "Timer: " << (minutes < 10 ? "0" : "") << minutes << ":"
                        << (secs < 10 ? "0" : "") << secs << endl;
                    cout << "Press 'p' to pause/resume the timer" << endl;
                    cout << "Press 'q' to quit the timer" << endl;
                    Sleep(1000); // Wait for one second
                    --seconds; // Decrease the seconds
                }

                if (_kbhit()) { // Check if a key is pressed
                    char ch = _getch();
                    if (ch == 'p' || ch == 'P') {
                        paused = !paused; // Toggle pause state
                    } else if (ch == 'q' || ch == 'Q') {
                        cout << "Timer stopped." << endl;
                        break; // Exit the loop if 'q' is pressed
                    }
                }
            }
            if (seconds < 0) {
                cout << "Time's up!" << endl;
                assistant.speak("Time's up!");
                Sleep(3000); // Give a moment to display "Time's up!" message
            }
        }

        void set_alarm(int hour, int minute, const string& period) {
            // Convert 12-hour format to 24-hour format
            if (period == "PM" || period == "pm" && hour != 12) {
                hour += 12;
            } else if (period == "AM" || period == "am" && hour == 12) {
                hour = 0;
            }

            while (true) {
                system("cls");
                time_t now = time(0);
                tm *lt = localtime(&now);
                int current_hour = lt->tm_hour;
                int current_minute = lt->tm_min;

                cout << "Current time: " << (current_hour > 12 ? current_hour - 12 : current_hour)
                     << ":" << (current_minute < 10 ? "0" : "") << current_minute
                     << (current_hour >= 12 ? " PM" : " AM") << endl;

                cout << "Alarm set for: " << (hour > 12 ? hour - 12 : hour)
                    << ":" << (minute < 10 ? "0" : "") << minute
                    << (hour >= 12 ? " PM" : " AM") << endl;

                if (current_hour == hour && current_minute == minute) {
                    cout << "Alarm ringing!" << endl;
                    for (int i = 0; i < 5; ++i) {
                        Beep(523, 500); // Beep sound for the alarm
                    }
                    Sleep(3000); // Give a moment to display "Alarm ringing!" message
                    break;
                }

                Sleep(1000); // Check every second
            }
        }

        void clock_menu() {
            while (true) {
                system("cls");
                cout << "1. Show Current Time" << endl;
                cout << "2. Start Timer" << endl;
                cout << "3. Set Alarm" << endl;
                cout << "4. Back to Main Menu" << endl;

                string message = "What would you like to do? Speak out the name of option to proceed.";
                cout << message << endl;
                assistant.speak(message);
                string choice = assistant.run();

                system("cls");

                char option;

                if(choice == "show current time") {
                    option = '1';
                } else if(choice == "start timer") {
                    option = '2';
                } else if(choice == "set alarm") {
                    option = '3';
                } else if(choice == "back to main menu") {
                    option = '4';
                } else {
                    option = '0';
                }

                switch (option) {
                    case '1':
                        showtime();
                        break;
                    case '2': {
                        int seconds;

                        cout << "Speak timer duration in seconds: ";
                        assistant.speak("Speak timer duration in seconds");
                        seconds = parseNumber(assistant.run());
                        
                        start_timer(seconds);
                        break;
                    }
                    case '3': {
                        int hour, minute;
                        string period;

                        cout << "Speak the hour for the alarm: ";
                        assistant.speak("Speak the hour for the alarm");
                        hour = parseNumber(assistant.run());

                        cout << "Speak the minute for the alarm: ";
                        assistant.speak("Speak the minute for the alarm");
                        minute = parseNumber(assistant.run());

                        cout << "Speak AM or PM for the alarm: ";
                        assistant.speak("Speak AM or PM for the alarm");
                        period = assistant.run();
                        
                        set_alarm(hour, minute, period);
                        break;
                    }
                    case '4':
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