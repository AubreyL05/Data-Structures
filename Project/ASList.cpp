#include "ASList.h"
#include <iostream>

ASList::ASList() {
    length = 0;
}

void ASList::PutItem(const Patient& p) {
    int i = length - 1;
    while (i >= 0 && !(data[i] > p)) {
        data[i + 1] = data[i];
        i--;
    }
    data[i + 1] = p;
    length++;
}

void ASList::print() const {
    for (int i = 0; i < length; i++){
        cout << "("
             << data[i].patientID << ", "
             << data[i].age << ", "
             << data[i].procedure << ", "
             << data[i].cost << ", "
             << data[i].length_of_stay
             << ")" << endl;
    }
}

void ASList::printFiltered(int days) const {
    for (int i = 0; i < length; i++) {
        if (data[i].length_of_stay >= days) {
            cout << "("
                 << data[i].patientID << ", "
                 << data[i].age << ", "
                 << data[i].procedure << ", "
                 << data[i].cost << ", "
                 << data[i].length_of_stay
                 << ")" << endl;
        }
    }
}