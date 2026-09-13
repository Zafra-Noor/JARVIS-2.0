#include <iostream>
#include <cmath>

#include "voiceRecognition.h"
#include "numberConverter.h"

using namespace std;

class Calculator {
    private:
        SpeechAssistant assistant;
    public:
        void add(double num1, double num2) {
            double result = num1 + num2;
            cout << "Result: " << result << endl;
            assistant.speak("The result is " + to_string(result));
        }

        void subtract(double num1, double num2) {
            double result = num1 - num2;
            cout << "Result: " << result << endl;
            assistant.speak("The result is " + to_string(result));
        }

        void multiply(double num1, double num2) {
            double result = num1 * num2;
            cout << "Result: " << result << endl;
            assistant.speak("The result is " + to_string(result));
        }

        void divide(double num1, double num2) {
            if (num2 == 0) {
                cout << "Error: Division by zero is undefined." << endl;
                assistant.speak("Error: Division by zero is undefined.");
            } else {
                double result = num1 / num2;
                cout << "Result: " << result << endl;
                assistant.speak("The result is " + to_string(result));
            }
        }

        void power(double base, double exponent) {
            double result = pow(base, exponent);
            cout << "Result: " << result << endl;
            assistant.speak("The result is " + to_string(result));
        }

        void squareRoot(double num) {
            if (num < 0) {
                cout << "Error: Square root of a negative number is undefined." << endl;
                assistant.speak("Error: Square root of a negative number is undefined.");
            } else {
                double result = sqrt(num);
                cout << "Result: " << result << endl;
                assistant.speak("The result is " + to_string(result));
            }
        }

        void calculatorMenu() {
            cout << "Calculator Menu:" << endl;
            cout << "1. Addition (+)" << endl;
            cout << "2. Subtraction (-)" << endl;
            cout << "3. Multiplication (*)" << endl;
            cout << "4. Division (/)" << endl;
            cout << "5. Square Root (sqrt)" << endl;
            cout << "6. Power (^)" << endl;
            cout << "0. Return to main menu" << endl;

            assistant.speak("What would you like to do in the Calculator? Speak out the name of option to proceed.");
            string calc_choice = assistant.run();

            int choice;

            if(calc_choice == "addition") {
                choice = 1;
            } else if(calc_choice == "subtraction") {
                choice = 2;
            } else if(calc_choice == "multiplication") {
                choice = 3;
            } else if(calc_choice == "division") {
                choice = 4;
            } else if(calc_choice == "square root") {
                choice = 5;
            } else if(calc_choice == "power") {
                choice = 6;
            } else if(calc_choice == "return") {
                choice = 0;
            } else {
                assistant.unknownCommand();
                return;
            }

            double num1, num2;
            switch (choice) {
                case 1:
                    assistant.speak("Speak the first number");
                    cout << "Speak the first number: ";
                    num1 = parseNumber(assistant.run());

                    assistant.speak("Speak the second number");
                    cout << "Speak the second number: ";
                    num2 = parseNumber(assistant.run());

                    add(num1, num2);
                    break;
                case 2:
                    assistant.speak("Speak the first number");
                    cout << "Speak the first number: ";
                    num1 = parseNumber(assistant.run());

                    assistant.speak("Speak the second number");
                    cout << "Speak the second number: ";
                    num2 = parseNumber(assistant.run());

                    subtract(num1, num2);
                    break;
                case 3:
                    assistant.speak("Speak the first number");
                    cout << "Speak the first number: ";
                    num1 = parseNumber(assistant.run());

                    assistant.speak("Speak the second number");
                    cout << "Speak the second number: ";
                    num2 = parseNumber(assistant.run());

                    multiply(num1, num2);
                    break;
                case 4:
                    assistant.speak("Speak the first number");
                    cout << "Speak the first number: ";
                    num1 = parseNumber(assistant.run());

                    assistant.speak("Speak the second number");
                    cout << "Speak the second number: ";
                    num2 = parseNumber(assistant.run());

                    divide(num1, num2);
                    break;
                case 5:
                    assistant.speak("Speak the number");
                    cout << "Speak the number: ";
                    num1 = parseNumber(assistant.run());

                    cin >> num1;
                    break;
                case 6:
                    assistant.speak("Speak the base number");
                    cout << "Speak the base number: ";
                    num1 = parseNumber(assistant.run());

                    assistant.speak("Speak the exponent");
                    cout << "Speak the exponent: ";
                    num2 = parseNumber(assistant.run());

                    power(num1, num2);
                    break;
                case 0:
                    cout << "Returning to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
};