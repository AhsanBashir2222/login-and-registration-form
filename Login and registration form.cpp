#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

void login();
void registration();
void forget();
void show();

void show() {
    string var1 = "_____________________________________________________________________"
                  "\n|                 Welcome to the login page                          |"
                  "\n|                           Menu                                     |"
                  "\n|____________________________________________________________________|"
                  "\n| \t Press 1 to login                                             |"
                  "\n| \t Press 2 to Register                                          |"
                  "\n| \t Press 3 to forget                                            |"
                  "\n| \t Press 4 to Exit                                              |"
                  "\n|___________________________________________________________________|";

    for (int i = 0; i < var1.size(); i++) {
        Sleep(10);
        cout << var1[i];
    }
}

int main() {
    show();
    cout << endl << endl;
    int n;
    cout << "Enter your choice: ";
    cin >> n;
    switch (n) {
        case 1:
            login(); // Call login function
            break;
        case 2:
            registration(); // Call registration function
            break;
        case 3:
            forget(); // Call forget function
            break;
        case 4:
            cout << "\t\t\t Thank you!" << endl;
            break;
        default:
            system("cls");
            cout << "\t\t\t Please select from 1-4 options." << endl;
            main(); // Loop back to main
    }
}

void login() {
    int count = 0; // Initialize count
    string username, password, id, pass;
    cout << "\t\t\t Please Enter the user Id and password:" << endl;
    cout << "\t\t\t Enter USERNAME: ";
    cin >> username;
    cout << "\t\t\t Please Enter the password: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == username && pass == password) {
            count = 1; // Successful login
            break; // Exit the loop
        }
    }
    input.close();

    if (count == 1) {
        cout << username << ", your login is successful. Thank you!" << endl;
        main(); // Return to main menu
    } else {
        cout << "Login Error. Please check the username and password." << endl;
        main(); // Return to main menu
    }
}

void registration() {
    string usname, password;
    system("cls");
    cout << "\t\t\t Enter the user name: ";
    cin >> usname;
    cout << "\t\t\t Enter the user Id: ";
    cin >> password;

    ofstream f1("records.txt", ios::app); // Append to the file
    f1 << usname << " " << password << endl; // Add a new line after each entry
    f1.close(); // Close the file

    system("cls");
    cout << "Registration is successful." << endl;
    main(); // Return to main menu
}

void forget() {
    int option;
    system("cls");
    cout << "You forgot the password. No worries." << endl;
    cout << "Press 1 to search for your ID." << endl;
    cout << "Press 2 to go back to menu: ";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string username, name, id;
            cout << "Enter the name you remembered: ";
            cin >> username;

            ifstream input("records.txt");
            while (input >> name >> id) {
                if (username == name) {
                    count = 1; // Account found
                    break; // Exit the loop
                }
            }
            input.close();

            if (count == 1) {
                cout << "Your password is found." << endl;
                cout << "Your password is: " << id << endl;
                main(); // Return to main menu
            } else {
                cout << "Sorry, your account is not found." << endl;
                main(); // Return to main menu
            }
            break;
        }
        case 2:
            main(); // Return to main menu
            break;
        default:
            cout << "Wrong choice. Please try again." << endl;
            forget(); // Retry the forget function
    }
}

