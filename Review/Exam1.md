# EXAM 1 Review

## Software Engineering Models
* **Waterfall Model**
    * Weakness: **Simple and Straightforward**, It's easy to understand and manage, which makes it great for projects with stable, well-defined requirements.
    * Strength: **Inflexible to Change**, Since each phase is "locked" once completed, it's very difficult and expensive to incorporate changes. This can lead to the final product not meeting evolving customer needs.

* **Agile Model**
    * Weakness: **Less Predictable**, The flexible nature can make it difficult to accurately estimate the final cost, time, and scope upfront.
    * Strength: **Flexibility and Adaptability**, Welcomes changing requirements, even late in the project, due to short, iterative cycles (sprints).
* **Spiral**
    * Weakness: **Complex and Costly**, The constant focus on risk analysis and prototyping makes it more complex and expensive to implement, requiring significant management overhead.
    * Strength: **Strong Risk Management**, Explicitly focuses on identifying, analyzing, and mitigating risks in every phase, making it ideal for large, complex, and high-risk projects.

## C++ Basics
* namespace
    * A namespace is a declarative region that provides a scope to the identifiers (variables, functions, classes, etc.) inside it. Its main purpose is to prevent name conflicts. For example, if two different libraries define a function with the same name, you can use namespaces to distinguish between them.
* Pointers, `*` and `&` operators, `->` operator
    * A pointer is a variable that stores the memory address of another variable. The `*` and `&` operators are essential for working with pointers:

        * The `&` (address-of) operator returns the memory address of a variable.

        * The `*` (dereference) operator accesses the value at the memory address stored in a pointer.

        * The `->` (arrow) operator is a shorthand used to access a member (a function or variable) of a struct or class through a pointer to that object. For example, `p->member` is the same as `(*p).member`.
* Dynamic allocation, new keyword
    * Dynamic allocation is the process of allocating memory at runtime rather than compile-time. The `new` keyword is used to dynamically allocate memory for an object or an array of objects on the heap. It returns a pointer to the newly allocated memory. For every `new` call, there should be a corresponding `delete` call to free the memory and prevent memory leaks.
* Insertion (`<<`) and Extraction (`>>`) Operators
    * The insertion (`<<`) and extraction (`>>`) operators are used for I/O operations with streams like cin and cout.
        * The `<<` (insertion) operator is used to "insert" data into an output stream, like writing to the console with cout.
        * The `>>` (extraction) operator is used to "extract" data from an input stream, like reading from the keyboard with cin.

* public and private keywords
    * public and private are access specifiers used within classes and structs to control the visibility of their members (variables and functions).
        * Public members are accessible from anywhere in the program. They form the interface of the class.
        * Private members are only accessible from within the same class. They are used to hide the internal implementation details from the outside world, a concept known as encapsulation.

* Source (.cpp) and header (.h) files
    * C++ programs are typically split into header (.h) and source (.cpp) files to manage code organization and compilation.

        * A header file contains declarations of classes, functions, and variables. It's used to tell the compiler about the existence of these components.

        * A source file contains the definitions (the actual implementation code) for the declarations in the header file.
* A constructor is a special member function of a C++ class that's automatically called when an object of that class is created. Its primary purpose is to initialize the object's data members.

### Passing Arguments to Functions
* By **value** - A copy of the argument is passed; the original argument cannot be modified by the function `value = 40998.33`.
* By **reference** - The function recieves

### Conditions on Functions
* **Precondition** A condition that must be true before an operation is executed.
* **Postconditions** A condition that will be true after an operation completes.
* **Preconditions/postconditions** are seen as a software contract.

## 1D Arrays
* **Arrays** are finite, fixed-size collections of ordered homogeneous elements.
* Permit direction, random access of elements using indices.
* Arrays can also be treated as pointers to the first elements.
* Method to index. The following all access the third element.
    * `myArray[2]`
    * `*(myArray[2])`

## Classes and Structs
* Classes:
    ```C++
    class Car {
    private:
        std::string color;
        int year;

    public:
        // Constructor to initialize the Car object
        Car(std::string c, int y) {
            color = c;
            year = y;
        }

        // A public function to display car details
        void displayDetails() {
            std::cout << "This is a " << color << " car from " << year << "." << std::endl;
        }
    };
    ```
* Struct:
    ```C++
    struct Point {
        int x;
        int y;

        // A member function to print the coordinates
        void print() {
            std::cout << "Coordinates: (" << x << ", " << y << ")" << std::endl;
        }
    };
    ```
## Abstraction
A simplified model of a complex system focusing only on essential details for a specific audience
* Abstract Data Types
    * High-level abstraction of information storage
    * Should be platform independent
    * Should have a predefined set of operators that can be utilized, given any implementation.

## Data Structures
* Implementations
    * Actual coded data structures to represent data types.
    * Should reflect low-level details (use of arrays/linked-lists, etc.)
    * Slight changes to ADT (e.g, sorted to unsorted) can drastically change the implementation

## Big-O
### Comparison of Algorithms
* Comparing execution time: Too many assumptions, varies greatly between different computers
* Compare number of instructions: Varies greatly due to different languages, compilers, programming styles...
* Instead, consider Big-O Notation

### Big-O Notation
* The best way to compare algorithms is by the amount of work done in the critical loop, as a function of the number of input elements (N).
* **Big-O:** A notation expressing --------

### Common Orders of Magnitude
* `O(1)`: Constant or bounded time; not affected by N at all.
* `O(logN)`: Log
* `O(N)`: Linear
* `O(NlogN)` : Linear Log time
* `O(N^2)`: Quadratic time
* `O(2^N)`: Exponential time

## Abstract Data Types (ADTs)
* Unsorted List
    * We have access to any part of the list for retrieval, addition, or removal.
    * Composed of items without any distinct order.
    * The main benefit is the ability to add to the list quickly, regardless of implementation
    * No efficient approach
* Sorted List
    * Data appears in the list in sorted order
    * Identical operators to those of the Unsorted List ADT
        * But their performance differs drastically, depending upon implementation.
    * We lost the ability to maintain the order of original entries in the list.
### ADT Operator Categories
* Operations on ADTs can be classified as:
    * **Constructors** - Create new instances (objects) of an ADT.
    * `PutItem`
    * `DeleteItem`
    * `MakeEmpty`
    * `GetLength`
    * `IsFull`
    * `ResetList` -ITERATORS
    * `GetNextItem` - ITERATORS

## Stack (LIFO)
* Data are added, looked at, and retrieved from only the top of the stack.
* Highly simplified data type and operations.
* Guarantees efficient manipulation, regardless of structure.
### Operations
* `Push` Adds an item to the top
* `Pop` Removes the top item
* `Peek` Returns the item at the top of the stack, but doesn't remove it
* `IsEmpty` 
* `IsFull`


## Queue (FIFO)
* Data are added at one end (rear), and retrieved or looked at from the other end (front).
* Generally more useful in real-world applications.
### Operations
* `Enqueue` Adds an item to the rear
* `Dequeue` Removes an item from the front
* `IsEmpty`
* `IsFull`
* `MakeEmpty`

### ADTS
```cpp
#define maxSize 100
struct LNode{
    int item;
    LNode* next;
}

class AUList{
    private:
        int items[maxSize];
        int length;
}

class LLUList{
    LNode* head;
}
```

### Critical Differences
* `AUList` always adds items to the **end** of the array.
* `LLUList` always adds items to the **head** of the linked list.
* `ASList` and `LLSList` add items according to their **ordered position in the list**

### `DeleteItem`
* All of the list implementations require `O(N)` worst-case time to delete items in the list.
### `GetItem`
* Any list implementation can use linear search `O(N)` to find an item.
* Only the `ASList` offers binary search `O(logN)`, because it has sorted order and random access.

## Stack Implementations
* `ArrayStack` Adds and removes from the end
* `LinkStack` Adds and removes from the head

## Queue Implementations
### Array
* Floating Queue
    * Let front and read indices **float** within the queue.

### Linked-List
* LLQueue
    * Enqueue would be inefficient without a secondary rear pointer.
    * Dequeue is efficient regardless.
* CLQueue
    * The class only has a pointer to the rear of the queue
    * Instead of pointing to NULL, the last node's next points to the front of the queue.
    * Works almost identically to the LLQueue.

### Comparison Takeaways
* Unsorted vs Sorted List ADT: `PutItem`, `GetItem`(for ASList only)
* Array-based vs LL-based: **Pre-paid** vs **Pay-as-you go**, LL needs an `O(N)` destructor, LL needs to store pointers (in nodes) beyond values.
* AUList vs LLUList: `MakeEmpty`, `GetLength*`
* ASList vs LLSList: `MakeEmpty`, `GetItem`, `PutItem`, `DeleteItem`, `GetLength`.
