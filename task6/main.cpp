#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ofstream outFile("grades.txt");
    if(!outFile){
        cout << "Error creating grades.txt!" << endl;
    }

    outFile << 85 << endl;
    outFile << 90 << endl;
    outFile << 70 << endl;
    outFile << 95 << endl;
    outFile << 60 << endl;

    outFile.close();

    ifstream inFile("grades.txt");
    if(!inFile){
        cout << "Error opening grades.txt for reading!" << endl;
        return 1;
    }

    int grade;
    cout << "Grades in file" << endl;
    while(inFile >> grade){
        cout << grade << endl;
    }
    inFile.close();

    int gradeToDelete;
    cout << "Enter a grade  to delete : ";
    cin >> gradeToDelete;

    ifstream origFile("grades.txt");
    ofstream tempFile("temp.txt");

    if(!origFile || !tempFile){
        cout << "Error opening files for update!" << endl;
        return 1;
    }

    bool found = false;
    while(origFile >> grade){
        if(grade != gradeToDelete){
            tempFile << grade << endl;
        }else{
            found = true;
        }
    }

    origFile.close();
    tempFile.close();

    if (remove("grades.txt") != 0 || rename("temp.txt", "grades.txt") != 0) {
        cout << "Error updating the file!" << endl;
    } else {
        if (found)
            cout << "Grade deleted and file updated successfully!" << endl;
        else
            cout << "Grade not found, file remains unchanged." << endl;
    }

    return 0;
}
