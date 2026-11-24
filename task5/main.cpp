#include <iostream>
#include <fstream>
using namespace std;
struct Student{
    char name[20];
    int id;
    float grade;
    char delim = '$';
};

int main()
{
    ofstream outFile("students.txt",ios::app);
    if(!outFile.is_open()){
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student s;
    char choice;

    do {
        cout << "Enter Student Name: ";
        cin.getline(s.name, 20);

        cout << "Enter Student ID: ";
        cin >> s.id;

        cout << "Enter Student Grade: ";
        cin >> s.grade;

        outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "Records saved successfully to students.txt!" << endl;

    return 0;
}
