# Instructions for Binary Search Tree (BST) Enhancement Assignment

## Overview

This assignment requires you to extend the provided Binary Search Tree (BST) implementation by adding two new member functions:

1. `int BST::GetHeight()`
2. `void BST::SplitBalance()`

You must use the provided `BST.cpp` and `BST.h` files as your base implementation. **Do not use any external BST versions.**

---

## Function Requirements

### `int BST::GetHeight()`

**Description:**  
Returns the height of the BST, defined as the maximum number of edges from the root node to any descendant.  
- An empty tree has a height of `-1`.  
- A single-node tree has a height of `0`.

**Example:**  
For the tree rooted at 14 with the longest path `14 → 5 → 8 → 12 → 10`,  
`myBST.GetHeight()` should return `4`.

---

### `void BST::SplitBalance()`

**Description:**  
Rebalances the BST using the split-balancing algorithm covered in Session 24.

**Recommended Steps:**
1. Store BST elements in sorted order using an in-order traversal.
2. Rebuild the BST using the sorted elements and the split-balancing algorithm.

**Notes:**
- Assume up to 10,000 elements may be in the BST.
- You may use a fixed-length array or a dynamic array (`std::vector`).
- Do not assume any specific values or structure of the tree.

---

## Guidelines

- Match all function names, return types, and parameters exactly.
- Always initialize variables explicitly (e.g., `int count = 0;`).
- Helper functions may be added if declared properly in `BST.h`.

---

---

## Visual GetHeight()
```markdown
         14
        /  \
       5    20
      / \     \
     3   8     25
        / \
       7   12
```
1. Start at **root (14)**  
   - Go left → **5**  

2. At **5**  
   - Go left → **3**  

3. At **3**  
   - Left child `nullptr` → returns -1  
   - Right child `nullptr` → returns -1  
   - Height at node 3 → `max(-1, -1) + 1 = 0`  

4. Back at **5**, now explore right → **8**  
   - Left child → **7**  
     - Both children `nullptr` → height = 0  
   - Right child → **12**  
     - Both children `nullptr` → height = 0  
   - Height at node 8 → `max(0, 0) + 1 = 1`  

5. Height at **5** → `max(leftHeight 0, rightHeight 1) + 1 = 2`

6. Back at **14**, now explore right → **20**  
   - Left child `nullptr` → height = -1  
   - Right child → **25** → both children `nullptr` → height = 0  
   - Height at 20 → `max(-1, 0) + 1 = 1`

7. Finally, height at **14** → `max(leftHeight 2, rightHeight 1) + 1 = 3`

---

## Visual SplitBalance()

```markdown
         10                                           5
        /  \                                        /   \
       5    15            Vector 'Nodes'           1    15
      /       \       [10, 5, 2, 1, 15, 20]         \  /  \
     2         20 ->    In-Order Traversal  ->       2|10  20
    /                 [1, 2, 5, 10, 15, 20]
   1                  
```
1. We are given at first an unbalanced tree consisting of [10, 5, 2, 1, 15, 20]. These values need to be reordered into In-Order traversal using `ResetTree(IN_ORDER)` which will then be put into the `TravQue`. Which is then dequeued into the vector `nodes`. -> [1, 2, 5, 10, 15, 20]

2. When all nodes are dequeued we next need to destroy the old tree using `MakeEmpty()`

3. After the old tree is destroyed we can start rebulilding the new balanced tree. In `SplitBalance()` `root = BalanceTree(nodes, 0, GetLength() - 1);` which will return the new root which will be the middle value of the In-Order traversal. The recursive function will also build the balanced tree aswell.

```cpp
TNode* BST::BalanceTree(vector<int>& nodes, int start, int end){
  if (start > end) return nullptr; // Base case

  int mid = start + (end-start)/2;

  TNode* newRoot = new TNode;
  newRoot->item = nodes[mid];

  newRoot->left = BalanceTree(nodes, start, mid - 1);
  newRoot->right = BalanceTree(nodes, mid + 1, end);
  return newRoot;
}
```

4. Finding out which node should be the new root of the balanced tree is just finding the middle value of the In_Order traversal. Then create a new node to return called `newRoot` which is assigned to `nodes[mid];` in the example given this would return **nodes[0 + (5-0)/2] = nodes[2] = 5**.

5. Now that we have our new root we can start rebuilding the tree, first we start with the left subtree.
   * `BalanceTree(nodes, 0, 1);` Will find that the new root is nodes[0 + 1/2] = nodes[0] = 1.
   * `BalanceTree(nodes, 0, -1);` -> Base case will stop it. So nothing to the left of 1 and now can look at the right of 1.
   * `BalanceTree(nodes, 1, 1);` will find the new node to be nodes[1 + 0/2] = nodes[1] = 2, so to the right of 1 is 2.
   * `BalanceTree(nodes, 1, 0);` & `BalanceTree(nodes, 2, 1);` will both return base case so this is the end of the left subtree.

6. After left subtree is completed we can move onto the right subtree.
   * `BalanceTree(nodes, 3, 5);` Will find the root of the right subtree to be nodes[3 + 2/2] = nodes[4] = **15**.
   * `BalanceTree(nodes, 3, 3);` Check the left of 15 which fill find the new node to be nodes[3 + 0/2] = nodes[3] = **10**.
   * Then it will recursive call for both left and right of 10 that will be stopped by base case.
   * `BalanceTree(nodes, 5, 5);` Check the right side of 15 which will find the new node to be nodes[5 + 0/2] = nodes[5] = **20**.
   * Then will will recursive call for both left and right of 20 which will be stopped by base cases.

7. After the subtrees are completed and the recursive calls are done it will return the newRoot, **5**.

## Compiling

To test your functions, use a `main.cpp` file and compile with:
```bash
g++ main.cpp BST.cpp CLQueue.cpp -o bst_test
./bst_test
```