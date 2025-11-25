#include "PQueue.h"
#include <iostream>

PQueue::PQueue() {
    length = 0;
}

void PQueue::ReheapUp(int top, int bottom) {
    if (bottom > top) {
        int parent = (bottom - 1) / 2;
        // Swap if child is greater than parent
        if (data[bottom].ev50 > data[parent].ev50) {
            swap(data[bottom], data[parent]);
            ReheapUp(top, parent);
        }
    }
}

void PQueue::ReheapDown(int top, int bottom) {
    int left = 2*top + 1;
    int right = 2*top + 2;
    int largest = top;

    if (left <= bottom && data[left].ev50 > data[largest].ev50)
        largest = left;

    if (right <= bottom && data[right].ev50 > data[largest].ev50)
        largest = right;

    if (largest != top) {
        swap(data[top], data[largest]);
        ReheapDown(largest, bottom);
    }
}

// Ensures structure is a correct max heap
bool PQueue::checkMaxHeap() const {
    for (int i = 0; i <= (length - 2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < length && data[i].ev50 < data[left].ev50) return false;
        if (right < length && data[i].ev50 < data[right].ev50) return false;
    }
    return true;
}

void PQueue::PutItem(const Player& p) {
    data[length] = p;
    ReheapUp(0, length);
    length++;
}

Player PQueue::GetItem() {
    Player maxItem = data[0];
    data[0] = data[length - 1];
    length--;
    ReheapDown(0, length - 1);
    return maxItem;
}

void PQueue::print() const {
    cout << left 
         << setw(5) << "Rank" 
         << setw(25) << "Name" 
         << setw(6) << "Team" 
         << setw(6) << "EV50" << endl;
    cout << "------------------------------------------------\n";

    for (int i = 0; i < length; i++) {
        cout << left 
             << setw(5) << data[i].rank
             << setw(25) << data[i].name
             << setw(6) << data[i].team
             << fixed << setprecision(1) << setw(6) << data[i].ev50
             << endl;
    }
}