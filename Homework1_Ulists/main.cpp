#include <iostream>
#include "AUList.h"
#include "LLUList.h"

int main(int argc, char** argv) {	
	AUList TestList;
	std::cout<<"Newly Created List: ";
	TestList.PrintList();
	for (int i=0; i<10; i++)
	  TestList.PutItem(100-i*10);
	std::cout<<"List after 'PutItem' (100 down to 10) calls: ";
	TestList.PrintList();

    std::cout << "Minimum value in AUList: " << TestList.getMin() << std::endl;
    std::cout << "Range of values in AUList: " << TestList.getRange() << std::endl;

	std::cout<<"Length after 'PutItem' calls: " <<TestList.GetLength() <<std::endl;
	std::cout<<"IsFull after 'PutItem' calls? " <<TestList.IsFull() <<std::endl;
	TestList.DeleteItem(50);
	std::cout<<"List after 'DeleteItem' (50) call: ";
	TestList.PrintList();
	std::cout<<"IsFull after 'DeleteItem' call? " <<TestList.IsFull() <<std::endl;
	std::cout<<"Index of value 80: "<<TestList.GetItem(80)<<std::endl;
	std::cout<<"Index of value 25: "<<TestList.GetItem(25)<<std::endl;
	TestList.MakeEmpty();
	std::cout<<"List after 'MakeEmpty': ";
    TestList.PrintList();
	
	
    LLUList TestList2;
	std::cout<<"Newly Created List: ";
	TestList2.PrintList();

	for (int i=0; i<10; i++)
	  TestList2.PutItem(100-i*10);
	std::cout<<"List after 'PutItem' calls: ";
	TestList2.PrintList();

    std::cout << "Minimum value in LLUList: " << TestList2.getMin() << std::endl;
    std::cout << "Range of values in LLUList: " << TestList2.getRange() << std::endl;

    AUList myAL;
    myAL.PutItem(55);
    myAL.PutItem(11);
    myAL.PutItem(33);
    myAL.PutItem(99);
    myAL.PutItem(77);
    myAL.PutItem(111);

    std::cout << "Original AUList: ";
    myAL.PrintList();

    AUList dup = myAL.DuplicateSE(1, 3);
    std::cout << "Duplicated sublist (1 to 3): ";
    dup.PrintList();

	std::cout<<"Length after 'PutItem' (100 down to 10) calls: " <<TestList2.GetLength() <<std::endl;
	std::cout<<"IsFull after 'PutItem' calls? " <<TestList2.IsFull() <<std::endl;
	TestList2.DeleteItem(50);
	std::cout<<"List after 'DeleteItem' (50) call: ";
	TestList2.PrintList();
	std::cout<<"Length of List: ";
	std::cout<<TestList2.GetLength()<<std::endl;
	std::cout<<"IsFull after 'DeleteItem' call? " <<TestList2.IsFull() <<std::endl;
	std::cout<<"Index of value 80: "<<TestList2.GetItem(80)<<std::endl;
	std::cout<<"Index of value 25: "<<TestList2.GetItem(25)<<std::endl;
	TestList2.MakeEmpty();
	std::cout<<"List after 'MakeEmpty': ";
	TestList2.PrintList();
	TestList2.ResetList();
	try {	
		TestList2.GetNextItem();
	} catch (...) {	
		std::cout<<"No items in list to iterate through."<<std::endl;
	}
	return 0;
}
