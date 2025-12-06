#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

#include "AUList.h"
#include "ASList.h"
#include "LLUList.h"
#include "LLSList.h"
#include "BST.h"

using namespace std;
using namespace std::chrono;

const int n = 1000;

AUList AUL;
ASList ASL;
LLUList LUL;
LLSList LSL;
BST BS;

class Timer {
public:
    void start() {
        m_StartTime = high_resolution_clock::now(); 
    }
    long long stop() {
        m_EndTime = high_resolution_clock::now();
        return duration_cast<microseconds>(m_EndTime - m_StartTime).count();
    }
private:
    time_point<high_resolution_clock> m_StartTime;
    time_point<high_resolution_clock> m_EndTime;
};

void printTable(const string& title, long long au, long long as, long long llu, long long lls, long long bst) {
    cout << title << endl;
    cout << "----------------------" << endl;
    cout << left
         << setw(12) << "DataStruct" 
         << setw(12) << "Time(µs)" << endl;
    cout << setw(12) << "AUList"  << setw(12) << au  << endl;
    cout << setw(12) << "ASList"  << setw(12) << as  << endl;
    cout << setw(12) << "LLUList" << setw(12) << llu << endl;
    cout << setw(12) << "LLSList" << setw(12) << lls << endl;
    cout << setw(12) << "BST"     << setw(12) << bst << endl << endl;
}

int main() {
    Timer timer;
    srand(time(nullptr));

    // Generate the same random numbers for all structures
    vector<int> values(n);
    for (int i = 0; i < n; i++) values[i] = rand() % 10000;

    // Insertion
    timer.start();
    for (int i = 0; i < n; i++) AUL.PutItem(values[i]);
    long long auin = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) ASL.PutItem(values[i]);
    long long asin = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) LUL.PutItem(values[i]);
    long long luin = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) LSL.PutItem(values[i]);
    long long lsin = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) BS.PutItem(values[i]);
    long long bsin = timer.stop();

    printTable("Insertion Complete", auin, asin, luin, lsin, bsin);

    // Searching
    timer.start();
    for (int i = 0; i < n; i++) AUL.GetItem(values[i]);
    long long ausearch = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) ASL.GetItem(values[i]);
    long long assearch = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) LUL.GetItem(values[i]);
    long long lusearch = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) LSL.GetItem(values[i]);
    long long llssearch = timer.stop();

    timer.start();
    for (int i = 0; i < n; i++) BS.GetItem(values[i]);
    long long bssearch = timer.stop();

    printTable("Searching Complete", ausearch, assearch, lusearch, llssearch, bssearch);

    // Deletion
    vector<int> shuffleValues = values;
    // Shuffle values for more accurate deletion time results
    shuffle(shuffleValues.begin(), shuffleValues.end(), default_random_engine(rand()));

    timer.start();
    for (int val : shuffleValues) AUL.DeleteItem(val);
    long long audel = timer.stop();

    timer.start();
    for (int val : shuffleValues) ASL.DeleteItem(val);
    long long asdel = timer.stop();

    timer.start();
    for (int val : shuffleValues) LUL.DeleteItem(val);
    long long ludel = timer.stop();

    timer.start();
    for (int val : shuffleValues) LSL.DeleteItem(val);
    long long llsdel = timer.stop();

    timer.start();
    for (int val : shuffleValues) BS.DeleteItem(val);
    long long bsdel = timer.stop();

    printTable("Deletion Complete", audel, asdel, ludel, llsdel, bsdel);

    return 0;
}
