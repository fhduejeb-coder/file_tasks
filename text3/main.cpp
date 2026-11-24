#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("welcome.txt");
    if (!file.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    file << "Hello Everybody";

    file.seekp(11, ios::beg);

    file << "one ";

    file.close();
    cout << "File updated successfully!" << endl;

    return 0;
}
