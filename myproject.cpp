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
void login()
{
    cout << "\n *Login*";

    string UserName, password;
    cout << "\n HELLOOOO ADMIN ENTER USERNAME: ";
    cin >> UserName;
    cout << " SHHHHHH ENTER PASSWORD(KEEP IT SECRET): ";
    cin >> password;

    if (UserName == adminUserName && password == adminPassword)
    {
        int adminChoice;
        do
        {
            cout << "\n Here These Are Admin Options:";
            cout << "\n 1. Take Attendance";
            cout << "\n 2. Add New Student";
            cout << "\n 0. Go Back to Main Menu";
            cout << "\n Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice)
            {
            case 1:
                takeAttendance();
                break;
            case 2:
                addNewStudent();
                break;
            case 0:
                break; // Go back to the main menu
            default:
                cout << "\n Invalid choice. Enter again.";
                getchar();
            }
        } while (adminChoice != 0);
    }
    else
    {
        cout << "\n Error! hehe you are not our admin";
        cout << "\n Press any key to return to the main menu.";
        getchar();
        getchar();
    }
}

void showAttendanceStats(int presentCount, int totalCount)
{
    float attendancePercentage = (presentCount * 100.0) / totalCount;

    cout << "----------------------\n";
    cout << "\nAttendance Statistics\n";
    cout << "----------------------\n";
    cout << "Total Students: " << totalCount << endl;
    cout << "Present: " << presentCount << endl;
    cout << "Absent: " << totalCount - presentCount << endl;
    cout << "Attendance Percentage: " << attendancePercentage << "%" << endl;
}
void takeAttendance()
{
    ifstream read("students.csv");
    ofstream attendanceFile("attendance.csv");

    int presentCount = 0;
    int totalCount = 0;

    Student student;
    string line;

    cout << "\nAttendance\n";
    cout << "\nPress Pfor present and a for Absent\n";
    cout << "---------------------\n";

    while (getline(read, line))
    {
        stringstream ss(line);
        getline(ss, student.rollnumber, ',');
        getline(ss, student.UserName, ',');
        cout << student.UserName << ": ";
        cin >> student.status;
        attendanceFile << student.rollnumber << "," << student.UserName << "," << student.status << "\n";

        if (student.status == 'p' || student.status == 'P')
        {

            presentCount++;
        }

        totalCount++;
    }

    cout << "\nAttendance marked successfully!";
    showAttendanceStats(presentCount, totalCount);
    cout << "\nPress any key to continue.";
    getchar();
    getchar();
}

void addNewStudent()
{
    cout << "\n ------- Add New Student -------";

    Student newStudent;
    cout << "\n Enter Roll no for the new student: ";
    cin >> newStudent.rollnumber;
    cout << " Enter Name for the new student: ";
    cin >> newStudent.UserName;

    ofstream write("students.csv", ios::app);

    write << newStudent.rollnumber << "," << newStudent.UserName << "\n";

    cout << "\n Student added successfully!";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}
