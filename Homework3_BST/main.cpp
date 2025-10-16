#include "BST.h"
//#include "CLQueue.h"

using namespace std;
int main() {
  BST myBST;
  myBST.PutItem(6);
  myBST.PutItem(3);
  myBST.PutItem(7);
  myBST.PutItem(9);
  myBST.PutItem(5);
  myBST.PutItem(1);
  BST clonedBST(myBST);
  myBST.DeleteItem(3);
  
  cout<<"My Tree: ";
  myBST.PrintTree();
  cout<<"Cloned Tree: ";
  clonedBST.PrintTree();
  clonedBST.MakeEmpty();
  cout<<"Cloned Tree V2: ";
  clonedBST.PrintTree();
  int curItem;
  myBST.ResetTree(PRE_ORDER);
  cout<<"My Tree Pre-Order: ";
  while (!(myBST.TravEmpty())) {
    cout<< myBST.GetNextItem();
    if (!myBST.TravEmpty())
      cout<<", ";
  }
  cout<<endl;
  
  myBST.ResetTree(POST_ORDER);
  cout<<"My Tree Post-Order: ";
  while (!(myBST.TravEmpty())) {
    cout<< myBST.GetNextItem();
    if (!myBST.TravEmpty())
      cout<<", ";
  }
  cout<<endl;

cout << "=== 2. Testing GetHeight() ===" << endl;
    
  // Height of the current tree
  int height1 = myBST.GetHeight();
  cout << "Height of My Tree (after deleting 3): " << height1 << endl;
    
  // Test a skewed tree (all right children)
  BST skewedBST;
  skewedBST.PutItem(10);
  skewedBST.PutItem(20);
  skewedBST.PutItem(30);
  skewedBST.PutItem(40);
  cout << "Inserting Skewed: 10, 20, 30, 40" << endl;
  skewedBST.PrintTree();
  int height2 = skewedBST.GetHeight();
  cout << "Height of Skewed Tree (4 nodes): " << height2 << " (Expected: 3)" << endl;

  // Test an Empty Tree
  BST emptyBST;
  int height3 = emptyBST.GetHeight();
  cout << "Height of Empty Tree: " << height3 << " (Expected: -1)" << endl;

  // Test a Single node Tree
  BST singleBST;
  singleBST.PutItem(67);
  int height4 = singleBST.GetHeight();
  cout << "Height of Single-Node Tree: " << height4 << " (Expected: 0)" << endl;
}
