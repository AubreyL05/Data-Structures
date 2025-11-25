#include <string>
#include <vector>
#include <iomanip>
#define MAXSIZE 250
using namespace std;

struct Player{
    int rank;
    string name;
    string team;
    float ev50;

    bool operator>(const Player& other) const {
        return ev50 < other.ev50; // descending (max heap)
    }
};

class PQueue {
private:
    Player data[MAXSIZE];
    int length;

    // helper functions
    void ReheapUp(int top, int bottom);
    void ReheapDown(int top, int bottom);

public:
    PQueue();

    bool checkMaxHeap() const;
    void PutItem(const Player& p);
    Player GetItem();

    void print() const;
};