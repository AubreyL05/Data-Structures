#include "ASList.h"
#include <iostream>
#include <sstream>
#include <fstream>

// Function to load CSV data into ASList
void loadCSV(const string& csv, ASList& list){
    ifstream file(csv);
    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        Patient p;
        string value;

        getline(ss, value, ',');
        p.patientID = stoi(value);

        getline(ss, value, ',');
        p.age = stoi(value);

        getline(ss, value, ',');
        p.procedure = value;

        getline(ss, value, ',');
        p.cost = stoi(value);

        getline(ss, value, ',');
        p.length_of_stay = stoi(value);

        list.insert(p);
    }
}

int main() {
    ASList patientList;
    cout << "loading csv..." << endl;
    loadCSV("HospitalDataset.csv", patientList);
    cout << "csv loaded" << endl;
    patientList.print();


    // EXTRA CREDIT: Filtering patients >= specified days
    cout << endl << "----------------------------------" << endl
    << "The list of patients sorted by length of stay (descending):" << endl;
    cout << "Would you like to specify an amount of days to filter by? (y/n): ";

    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the minimum length of stay (in days from 0-76): ";
        int minDays;
        cin >> minDays;
            while (minDays < 0 || minDays > 76 || cin.fail()) {
                cout << "Invalid input. Please enter a number of days between 0 and 76: ";
                cin >> minDays;
            }
        cout << "Patients with length of stay >= " << minDays << " days:" << endl;
        patientList.printFiltered(minDays);
    }

    return 0;
}