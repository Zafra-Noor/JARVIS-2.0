#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

class SpeechAssistant {
    public:

        string run() {
            string input;

            while (true) {
                string recognizedText = recognizeSpeech();

                system("echo \a");
                cout << "> ";

                if (!recognizedText.empty()) {
                    cout << recognizedText << endl;
                    input = recognizedText;
                }

                toLowerCase(input);

                if (input == "one") {
                    return "1";
                    break;
                } else if (input == "two") {
                    return "2";
                    break;
                } else if (input == "three") {
                    return "3";
                    break;
                } else if (input == "four") {
                    return "4";
                    break;
                } else if (input == "five") {
                    return "5";
                    break;
                } else if (input == "six") {
                    return "6";
                    break;
                } else if (input == "seven") {
                    return "7";
                    break;
                } else if (input == "eight") {
                    return "8";
                    break;
                } else if (input == "nine") {
                    return "9";
                    break;
                } else if (input == "zero") {
                    return "0";
                    break;
                } else if(!input.empty()) {
                    return input;
                    break;
                } else {
                    unknownCommand();
                }
            }
        }

        string recognizeSpeech() {
            system("python speechRecognition.py");
            ifstream file("recognized_text.txt");
            string recognizedText;
            if (!file.is_open()) {
                cout << "Error opening file" << endl;
                return "";
            }
            stringstream buffer;
            buffer << file.rdbuf();
            recognizedText = buffer.str();
            file.close();
            return recognizedText;
        }

        void speak(const string &text) {
            string command = "powershell -Command \"Add-Type -AssemblyName System.speech; "
                            "(New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('"
                            + text + "');\"";
            system(command.c_str());
        }

        void toLowerCase(string &str) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        }

        void greet() {
            string message = "Hello! How can I assist you today?";
            cout << message << endl;
            speak(message);
        }

        void unknownCommand() {
            string message = "I'm sorry, I didn't understand that command.";
            cout << message << endl;
            speak(message);
        }

        void quit() {
            string message = "Goodbye!";
            cout << message << endl;
            speak(message);
        }
};