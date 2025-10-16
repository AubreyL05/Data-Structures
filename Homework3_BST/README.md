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

## Compiling

To test your functions, use a `main.cpp` file and compile with:
```bash
g++ main.cpp BST.cpp -o bst_test
./bst_test
```