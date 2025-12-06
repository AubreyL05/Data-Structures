#include <iostream>
#include "LLSList.h"

struct LLSNode {
    int item;
    LLSNode* next;
};

LLSList::LLSList() {
  ListStart=NULL;  
}

LLSList::~LLSList() {
  LLSNode* tempPtr;
  while (ListStart != NULL) {
    tempPtr = ListStart;
    ListStart = ListStart->next;
    delete tempPtr;
  }
}

bool LLSList::IsFull() const {
  LLSNode* testNode;
  try {
    testNode = new LLSNode;
    delete testNode;
    return false;
  }
  catch(std::bad_alloc exception) {
    return true;
  }
}

int LLSList::GetLength() const {
  LLSNode* LenPos = ListStart;
  int length=0;
  while (LenPos != NULL) {  
	LenPos=LenPos->next;
	length++;
  }
  return length;
};

int LLSList::GetItem(int gitem) {
   int position=0;
   LLSNode* nodeIter;
   nodeIter=ListStart;
   while ((nodeIter != NULL) && (nodeIter->item <gitem)) {
      nodeIter=nodeIter->next;
      position++; }
   if ((nodeIter==NULL)||(nodeIter->item>gitem))
      return -1;
   else
      return position;
}

void LLSList::MakeEmpty() {
  LLSNode* tempPtr;
  while (ListStart != NULL) {
    tempPtr = ListStart;
    ListStart = ListStart->next;
    delete tempPtr;
  }  
}


void LLSList::PutItem(int newitem) {
  LLSNode* newNode; //Get a pointer for a new node 			
  LLSNode* leadptr; //This points to the "current" node when searching for correct location in which to place item
  LLSNode* trailptr; //This points to the "previous" node when searching for correct location in which to place item 			
  
  newNode = new LLSNode; //Allocate memory for the new node
  newNode->item = newitem; // Store the item in the node  
  if ((ListStart == NULL) || (ListStart->item > newitem)) { //List is empty or first element less than element for retrieval)
  	newNode->next = ListStart; // Store address of next node 
  	ListStart=newNode;
  	
  } else {
  	leadptr=ListStart->next;
  	trailptr=ListStart;
  	while ((leadptr!= NULL) && (leadptr->item<newitem)) {	  
  		leadptr=leadptr->next;
  		trailptr=trailptr->next;
	}
  	newNode->next=leadptr;
  	trailptr->next=newNode;
  }    
}

void LLSList::DeleteItem(int ditem) {
  LLSNode* nodeIter;
  LLSNode* tmpNode;
  LLSNode* leadptr; //This points to the "current" node when searching for correct location in which to place item
  LLSNode* trailptr; //This points to the "previous" node when searching for correct location in which to place item 	
  if (ListStart->item == ditem) {
    tmpNode=ListStart;
    ListStart=ListStart->next;
  } 
  else{
    leadptr=ListStart->next; //no empty lists allowed
    trailptr=ListStart;
    while (leadptr->item !=ditem) {
		trailptr=leadptr;
		leadptr=leadptr->next;     	
	}      
    tmpNode=leadptr;
    trailptr->next=leadptr->next;    
  }
  delete(tmpNode);
}


void LLSList::ResetList() {
  curPos=ListStart;
}

int LLSList::GetNextItem() {
  if (curPos == NULL)
    throw;
  curPos=curPos->next;
  return curPos->item;
};

void LLSList::PrintList() {
  LLSNode* printPtr;
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

