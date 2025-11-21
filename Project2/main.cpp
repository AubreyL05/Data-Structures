#include "PQueue.h"
#include <iostream>
#include <sstream>
#include <fstream>

// Function to load CSV data into PQueue
void loadCSV(const string& csv, PQueue& list){
    ifstream file(csv);
    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        Player p;
        string value;

        getline(ss, value, ',');
        p.rank = stoi(value);

        getline(ss, value, ',');
        p.name = value;

        getline(ss, value, ',');
        p.team = value;

        getline(ss, value, ',');
        p.ev50 = stof(value);

        list.PutItem(p);
    }
}

int main() {
    PQueue pq;
    cout << "loading csv..." << endl;
    loadCSV("EV50.csv", pq);
    cout << "csv loaded" << endl;

    pq.print();  // optional: prints the heap array

    if (pq.checkMaxHeap())
        cout << "Heap property is valid!\n";
    else
        cout << "Heap property is broken!\n";

    int input = 0;    
    cout << "Enter the number of top players to display (5 - 250):";
    cin >> input;

    if (input >= 5 && input <= 250){
        cout << "\nTop " << input << " EV50 Players: " << endl;
        cout << left 
             << setw(25) << "Name" 
             << setw(6) << "EV50" << endl;
        cout << "-----------------------------------\n";

        for (int i = 0; i < input && !pq.isEmpty(); i++) {
            Player p = pq.GetItem();  // pops max EV50
            cout << left 
                << setw(25) << p.name 
                << fixed << setprecision(1) << setw(6) << p.ev50 
                << endl;
        }
    }
    else {
        cout << "Not a valid input\n" << "Terminating Process";
    }

    return 0;
}
