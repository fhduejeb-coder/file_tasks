#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main()
{
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter name of person " << i + 1 << ": ";
        cin.ignore();
        getline(cin, p.name);

        cout << "Enter age of person " << i + 1 << ": ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    ifstream inFile("persons.txt");
    if (!inFile.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    vector<Person> people;
    Person temp;

    while (getline(inFile, temp.name)) {
        inFile >> temp.age;
        inFile.ignore();
        people.push_back(temp);
    }
    inFile.close();

    if (!people.empty()) {
        Person youngest = people[0];
        Person oldest = people[0];

        for (int i = 1; i < people.size(); i++) {
            if (people[i].age < youngest.age) {
                youngest = people[i];
            }
            if (people[i].age > oldest.age) {
                oldest = people[i];
            }
        }

        ofstream resFile("results.txt");
        if (resFile.is_open()) {
            resFile << "Youngest Person: " << youngest.name << " (" << youngest.age << " years old)" << endl;
            resFile << "Oldest Person: " << oldest.name << " (" << oldest.age << " years old)" << endl;
            resFile.close();
            cout << "Results saved successfully to results.txt!" << endl;
        }
    }
    return 0;
}
