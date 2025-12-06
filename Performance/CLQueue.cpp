#include "CLQueue.h"

CLQueue::CLQueue() {
  QEnd=NULL;
}
  
CLQueue::~CLQueue() {
  MakeEmpty();  
}
  
void CLQueue::MakeEmpty() {
  CLNode* tmpNode;
  
  if (QEnd !=NULL) {
  	CLNode* curNode=QEnd->next;
    while (curNode!=QEnd) {
      tmpNode=curNode;
      curNode=curNode->next;
      delete(tmpNode);
    }
  }
  delete(QEnd);
  QEnd=NULL;
}
  
bool CLQueue::IsEmpty() const {
  return (QEnd== NULL);
}
  
bool CLQueue::IsFull() const {
  CLNode* location;
  try {
    location = new CLNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception) {
    return true;
  }
}

void CLQueue::Enqueue(int newItem) {  
  CLNode* newNode = new CLNode;
  newNode->item = newItem;
  if (QEnd==NULL) {
    QEnd=newNode;
	QEnd->next=QEnd;	
  } else {
  	newNode->next = QEnd->next;
  	QEnd->next = newNode;
  	QEnd=newNode;
  }
}

int CLQueue::Dequeue() {
  if (QEnd==NULL)
    throw;
  else {
  	CLNode* tmpNode=QEnd->next;
    int retitem=tmpNode->item;
    if (QEnd->next == QEnd)
      QEnd=NULL;
    else
      QEnd->next=QEnd->next->next;
    delete(tmpNode);
	return retitem;    
  }
  
}




