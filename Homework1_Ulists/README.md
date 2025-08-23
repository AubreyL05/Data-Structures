# Homework: Unordered List Implementations

This directory contains my completed files for the Unordered List assignment, which involves adding functions to both Array-based (`AUList`) and Linked List-based (`LLUList`) implementations.

The following tasks have been completed as per the assignment instructions.

---

### Tasks

**1. (Easy) `int getMin()`**

* **Description:** A function for both `AUList` and `LLUList` that finds and returns the smallest element in the list.

* **Example:** For a list `{3, 2, 1, 4, 5, 6}`, `getMin()` returns `1`.

**2. (Medium) `int getRange()`**

* **Description:** A function for both `AUList` and `LLUList` that computes and returns the difference between the smallest and largest elements.

* **Example:** For a list `{3, 2, 1, 4, 5, 6}`, `getRange()` returns `5` (6 - 1).

**3. (Challenging) `AUList DuplicateSE(int first, int last)`**

* **Description:** A function for `AUList` that duplicates elements from a specified starting index (`first`) to an ending index (`last`), returning a new list without modifying the original.

* **Example:** For a list `{55, 11, 33, 99, 77, 111}`, calling `DuplicateSE(1, 3)` returns a new list `{11, 33, 99}`.

---

### Files Included

* `AUList.h`

* `AUList.cpp`

* `LLUList.h`

* `LLUList.cpp`

* `main.cpp` (A driver program to test the functionality)

* `myprogram` (An executable to run tests)

---

### Notes & Information

* The code is designed to handle edge cases such as empty lists. `getMin()` and `getRange()` will throw an `std::out_of_range` exception if called on an empty list.

* The `DuplicateSE` function for `AUList` handles invalid index ranges by returning an empty list, as specified by the problem.

* I've included a basic `main.cpp` file to serve as a driver for testing the functions with sample inputs.