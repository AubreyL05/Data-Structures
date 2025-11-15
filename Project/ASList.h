#include <string>
#define MAXSIZE 1000
using namespace std;

struct Patient{
    int patientID;
    int age;
    string procedure;
    int cost;
    int length_of_stay;

    bool operator>(const Patient& other) const {
        return length_of_stay > other.length_of_stay; // descending
    }
};

class ASList {
private:
    int length;
    Patient data[MAXSIZE];
public:
    ASList();
    
    void PutItem(const Patient& p);
    void print() const;
    void printFiltered(int days) const;
};