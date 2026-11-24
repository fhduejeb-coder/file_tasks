#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fullName, grade;
    int id;

    cout << "Enter Student Full Name: ";
    getline(cin, fullName);

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Student Grade: ";
    cin >> grade;

    ofstream studentFile;
    studentFile.open("Student.txt");

    if (!studentFile.is_open()) {
        cout << "Error, file is not opened" << endl;
    } else {
        studentFile << "Full Name: " << fullName << endl;
        studentFile << "ID: " << id << endl;
        studentFile << "Grade: " << grade << endl;
        cout << "Data saved successfully!" << endl;
    }

    studentFile.close();
    return 0;
}
