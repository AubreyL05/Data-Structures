# Instructions for String Decoding Assignment

## Overview

This assignment requires you to create a C++ function `decode` that manipulates strings based on a set of rules. You'll need to use the provided `StackType.h` and `QueType.h` header files to correctly process and order the characters.

---

## Files and Function Signature

* **Provided Files:** You must use the `StackType.h` and `QueType.h` files provided with the assignment. **Do not modify these files.**
* **Your File:** All your code must be contained within a single file named `stringdecoding.cpp`.
* **Function Signature:** The function you create must have the following exact signature:
    ```cpp
    std::string decode(std::string exp, std::string code);
    ```
    Note that the input arguments are `std::string`, not character arrays.

---

## Function Logic and Rules

The `decode` function should follow these specific rules:

1.  **Iterate through `exp`:** Loop through each character of the input string `exp`. It is recommended to use `std::string::at()` for this.
2.  **Process characters based on `code`:**
    * **Rule (i):** If a character from `exp` is **not** found in the `code` string, add it to the final output string, maintaining its original order.
    * **Rule (ii):** If a character from `exp` **is** found in the `code` string, store it separately. These "code" characters will be appended to the output string in **reverse order** after the non-code characters have been added.

---

## Recommended Approach

To solve this problem efficiently, it is recommended you use the provided data structures:

* **QueType<>:** A `QueType` instance is ideal for storing the non-code characters. Since a queue follows a First-In, First-Out (FIFO) principle, it will naturally maintain the original order of these characters.
* **StackType<>:** A `StackType` instance is perfect for storing the code characters. A stack's Last-In, First-Out (LIFO) principle means that when you pop the characters off the stack, they will be retrieved in the reverse order they were pushed, which is exactly what Rule (ii) requires.

---

## Example

* **Input:**
    * `exp`: `"czitqommta_ehmumt_nio_szozir_eulopupoa_yeht_"`
    * `code`: `"_acefhilnpst"`
* **Common Characters:** The characters common to both strings are: `_`, `c`, `t`, `a`, `e`, `h`, `m`, `u`, `n`, `i`, `o`, `s`, `z`, `r`, `p`, `y`.
* **Expected Output:** The non-code characters from `exp` are `"zqommmumozozruouoy_"`, and the code characters are `"the_apple_is_in_the_attic"`. The final decoded string is the combination of these two parts: `"zqommmumozozruouoy_the_apple_is_in_the_attic"`

---

## Additional Notes

* **Checking for Characters:** To check if a character from `exp` exists in `code`, use `std::string::find()`. **Do not use `contains()`,** as it may not be supported by the autograder. A character is found if `std::string::find()` does **not** return `std::string::npos`.
* **Helper Functions:** You may use helper functions, but they must all be defined within the `stringdecoding.cpp` file.
* **Include Directives:** Simply `#include "StackType.h"` and `#include "QueType.h"` in your `stringdecoding.cpp` file.
* **Variable Initialization:** Explicitly initialize all variables. For example: `int myInt = 0;`.