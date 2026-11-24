#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;

    ifstream readFile("fruit.txt");

    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Error opening file for reading!" << endl;
    }

    ofstream writeFile("fruit.txt", ios::app);
    if (writeFile.is_open()) {
        writeFile << "\nFresh Fruits";
        writeFile.close();
    } else {
        cout << "Error opening file for writing!" << endl;
    }

    return 0;
}
