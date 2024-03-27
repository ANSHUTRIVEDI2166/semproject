#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


struct Student
{
    string rollnumber;
    string UserName;
    char status;
};

const string adminUserName = "changa";
const string adminPassword = "changa69";

void login();
void takeAttendance();
void addNewStudent();
void displayMenu();
void showAttendanceStats(int presentCount, int totalCount);

int main()
{
    while (1)
    {
        displayMenu();

        int choice;
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            login();
            break;
        case 0:
            cout << "\n Are you sure you want to exit? (y/n): ";
            char exitChoice;
            cin >> exitChoice;
            if (exitChoice == 'y' || exitChoice == 'Y')
            {
                exit(0);
            }
            break;
        default:
            cout << "\n Invalid choice. Enter again.";
            getchar();
        }
    }

    return 0;
}

void displayMenu()
{
    cout << "Hey!!!! Welcome To The Server Of Charusat Attendance Management System :\n";
    cout << "1. press 1 for Login\n";
    cout << "0. press 0 for Exit\n";
}
