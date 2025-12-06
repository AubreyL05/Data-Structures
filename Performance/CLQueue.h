#include <iostream>

struct CLNode {
  public:
  int item;
  CLNode *next;
};

class CLQueue {
public: 
  CLQueue();
  ~CLQueue();
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(int newItem);
  int Dequeue();
//private:
  CLNode* QEnd;
};


