#include <iostream>
#include "LLUList.h"

struct LLUNode {
    int item;
    LLUNode* next;
};

LLUList::LLUList() {
  ListStart=NULL; 
  curPos = NULL; 
}

LLUList::~LLUList() {
  //Note: The destructor can have compability issues with the assignment operator in returns.  It is recommended for HW #1 that you keep the code commented out 
  /*
  LLUNode* tempPtr; 
  while (ListStart != NULL) {
    tempPtr = ListStart;
    ListStart = ListStart->next;
    delete tempPtr;
  }
  */
}

bool LLUList::IsFull() const {
  LLUNode* testNode;
  try {
    testNode = new LLUNode;
    delete testNode;
    return false;
  }
  catch (const std::bad_alloc& exception) {
    return true;
  }
}

int LLUList::GetLength() const {
  LLUNode* LenPos = ListStart;
  int length=0;
  while (LenPos != NULL) {
	LenPos=LenPos->next;
	length++;
  }
  return length;
};

int LLUList::GetItem(int gitem) { //Procedure is similar to that of AUList, although the relevant data is stored different.
								  //also, it's better for LLUList to proceed in order from the beginning
   int position=0;
   LLUNode* nodeIter;
   nodeIter=ListStart;
   while ((nodeIter != NULL) && (nodeIter->item !=gitem)) {
      nodeIter=nodeIter->next;
      position++; }
   if (nodeIter==NULL)
      return -1;
   else
      return position;
}

void LLUList::MakeEmpty() { //Unlike the AUList implementation, we need to step through and delete EVERY node
  LLUNode* tempPtr;
  while (ListStart != NULL) {
    tempPtr = ListStart;
    ListStart = ListStart->next;
    delete tempPtr;
  }  
}


void LLUList::PutItem(int newitem) {
  LLUNode* newNode; //Get a pointer 			
  newNode = new LLUNode; //Create a new node. 
  newNode->item = newitem; // Store the item in the node
  newNode->next = ListStart; // Store address of next node 
  ListStart = newNode; // Redirect start of list
}

void LLUList::DeleteItem(int ditem) { //A little bit tricky because we need to "scout ahead" and relink the object
									  //before the deleted object to the one after. 
  LLUNode *tmpNode, *nodeIter;
  if (ListStart->item == ditem) {
    tmpNode=ListStart;
    ListStart=ListStart->next;
  } 
  else{
    nodeIter=ListStart;
    while ((nodeIter->next->item !=ditem)) 
      nodeIter=nodeIter->next;
    tmpNode=nodeIter->next;
    nodeIter->next=(nodeIter->next)->next; 
  }
  delete(tmpNode);
}


void LLUList::ResetList() {
  curPos=ListStart;
}

int LLUList::GetNextItem() {
  int myitem;
  if (curPos == NULL) //The implemented option throw an errors if someone tries to access an item past the last one. 
    throw(38); //EOS Exception
  myitem = curPos->item;
  curPos=curPos->next;
  return myitem;
};

void LLUList::PrintList() {
  LLUNode* printPtr;
  printPtr=ListStart;
  std::cout<<"(";
  while (printPtr != NULL) {
    std::cout<<printPtr->item;
    if (printPtr->next!=NULL)
	  std::cout<<", ";
	printPtr=printPtr->next;
  }    
  std::cout<<")"<<std::endl;
}