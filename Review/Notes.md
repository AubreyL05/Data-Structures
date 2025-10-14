# CSE 302 Data Structures - Course Notes

## Course Overview
**Instructor:** Dr. Zeyan Liu  
**Focus:** Data structures fundamentals and implementation in C++

## Software Engineering Fundamentals

### Software Development Models
1. **Waterfall Model**: Linear, step-by-step approach
   - Pros: Straightforward structure
   - Cons: Costly to change, late deployment, poor for team dynamics

2. **Spiral Model**: Emphasizes risk assessment
   - Pros: Iterative refinement, risk-aware
   - Cons: Difficult when risks are hard to quantify

3. **Agile Model**: Small, iterative cycles
   - Pros: Flexible, client collaboration, adaptable to changing specs
   - Cons: Requires frequent communication

### Quality Software Goals
- **Accuracy**: Works correctly, meets requirements
- **Efficiency**: Meets runtime constraints
- **Accessibility**: Easy to modify and maintain
- **Reusability**: Components can be used elsewhere
- **Deployability**: Completed on time and within budget

## Abstraction and Data Types

### Key Concepts
- **Abstraction**: Simplified model focusing on essential details for specific audience
- **Information Hiding**: Keeping internal module details private
- **Program Specification**: What the program should do
- **Program Design**: How the program accomplishes its goals

### Design Approaches
- **Top-down**: Break goals into smaller parts
- **Bottom-up**: Start with details, build up
- **Functional Decomposition**: Program as cooperating functions
- **Object-Oriented Design**: Create object blueprints with specific tasks

## Data Views and Abstract Data Types (ADTs)

### Three Levels of Data Abstraction
1. **Application View**: User perspective, UI organization
2. **Logical View**: What operations are possible, main components
3. **Implementation View**: How data is stored in memory, actual C++ implementation

### ADT vs Data Structures
- **ADT**: Concept defining data type by behaviors and operations (what functionality)
- **Data Structure**: Physical implementation of ADT (how to achieve functionality)
- Multiple data structures can implement one ADT

## Composite Data Types

### Records (Unstructured)
- Collection of related elements (fields/members)
- Accessed using named selectors (object.fieldname)
- Implementation: Contiguous memory with calculated offsets

### Arrays (Structured)
- Finite, fixed-size collections of homogeneous elements
- Direct access using indices
- 1D: `array[index]`
- 2D: `table[row][col]` stored in row-major order

## C++ Classes and Implementation

### Class Basics
```cpp
class ClassName {
private:
    // Member variables (should be private)
    int data;
    
public:
    // Member functions (often public)
    ClassName();  // Constructor
    void operation();
};
```

### Key Features
- **Constructors**: Initialize objects, can be overloaded
- **Public Members**: Accessible by clients
- **Private Members**: Only accessible within class
- **Inheritance**: Classes can inherit from base classes
- **Polymorphism**: Function overloading and overriding

### Memory Management
- **Pointers**: Store memory addresses
- **Dynamic Allocation**: `new` keyword for runtime allocation
- **Deallocation**: `delete` to prevent memory leaks
- **Arrow Operator**: `ptr->member` equivalent to `(*ptr).member`

## Algorithms and Big-O Notation

### Big-O Analysis
- Measures how execution time scales with input size
- Focus on fastest-growing term
- Common complexities:
  - **O(1)**: Constant time
  - **O(log N)**: Logarithmic time
  - **O(N)**: Linear time
  - **O(N log N)**: Log-linear time
  - **O(N²)**: Quadratic time

### Search Algorithms
- **Linear Search**: O(N) - check each element
- **Binary Search**: O(log N) - requires sorted data, halves search space each iteration

## List ADTs and Implementations

### List Operations
- **Constructors**: Create empty or initialized lists
- **Transformers**: PutItem, DeleteItem, MakeEmpty
- **Observers**: IsFull, GetLength, GetItem
- **Iterators**: ResetList, GetNextItem

### Unsorted List Implementations

#### Array-based Unsorted List (AUList)
```cpp
class AUList {
private:
    int items[maxSize];
    int length;
    int currentPos;
};
```
- **PutItem**: Add at end, O(1)
- **DeleteItem**: Either move all elements O(N) or swap with last O(1)
- **GetItem**: Linear search O(N)

#### Linked List-based Unsorted List (LLUList)
```cpp
struct LNode {
    int item;
    LNode* next;
};

class LLUList {
private:
    LNode* ListStart;
    int length;
    LNode* curPos;
};
```
- **PutItem**: Add at beginning, O(1)
- **DeleteItem**: Find and reconnect pointers, O(N) search
- **Memory Management**: Manual deletion required

### Sorted List Implementations

#### Array-based Sorted List (ASList)
- **GetItem**: Can use binary search O(log N)
- **PutItem**: Find position + shift elements, O(N)
- **DeleteItem**: Find + move elements up, O(N)

#### Linked List-based Sorted List (LLSList)
- **GetItem**: Sequential search with early stopping, O(N)
- **PutItem/DeleteItem**: Use two pointers (lead/trail) for insertion/deletion

## Advanced Data Structures

### Dynamic Arrays and Vectors
- **std::vector**: Template class with dynamic sizing
- **push_back()**: Add elements dynamically
- **reserve()**: Pre-allocate capacity
- **at()**: Safe access with bounds checking

### Stack ADT (LIFO - Last In, First Out)
```cpp
class Stack {
public:
    void Push(item);     // Add to top
    Item Pop();          // Remove from top
    Item Peek();         // View top without removing
    bool IsEmpty();
    bool IsFull();
};
```

#### Implementations
- **ArrayStack**: Use array with top pointer
- **LLStack**: Linked list with operations at head

### Queue ADT (FIFO - First In, First Out)
```cpp
class Queue {
public:
    void Enqueue(item);  // Add to rear
    Item Dequeue();      // Remove from front
    bool IsEmpty();
    bool IsFull();
};
```

#### Implementations
- **Fixed-Front Queue**: Index 0 always front, inefficient dequeue O(N)
- **Floating Queue**: Both front and rear pointers, circular array
- **Linked List Queue**: Front and rear pointers to nodes

## Linked List Variants

### Circular Linked Lists
- Last node points back to first node
- Can use single pointer (ListEnd) for both access points
- Helpful for certain algorithms but adds complexity

### Doubly Linked Lists
```cpp
struct DLNode {
    int item;
    DLNode* next;
    DLNode* prev;
};
```
- Can traverse in both directions
- Eliminates need for "fast-slow" pointer techniques
- Higher memory overhead

### Advanced Variants
- **Double-ended**: Maintain both start and end pointers
- **Header/Trailer nodes**: Dummy nodes to simplify edge cases
- **Circular doubly-linked**: Combines benefits of multiple approaches

## Templates and Generic Programming

### Template Classes
```cpp
template <class ItemType>
class StackType {
private:
    ItemType items[MAX_SIZE];
public:
    void Push(ItemType item);
    ItemType Pop();
};
```

### Usage
```cpp
StackType<int> intStack;
StackType<string> stringStack;
```

## Stack Applications

### Function Call Stack
- Each function call creates stack frame
- Contains return address and local variables
- LIFO order matches function return pattern

### Parenthetical Expression Validation
Algorithm:
1. Push opening brackets onto stack
2. For closing brackets, pop and check for match
3. Stack should be empty at end for valid expression

## Testing and Debugging

### Types of Errors
1. **Specification/Design Errors**: Cheapest to fix early
2. **Compile-time Errors**: Syntax and type errors
3. **Runtime Errors**: Occur during execution

### Debugging Strategies
- **Print Debugging**: Output variable values at checkpoints
- **Breakpoint Debugging**: Pause execution to examine state
- **Design by Contract**: Use preconditions and postconditions

### Testing Approaches
- **Unit Testing**: Test individual modules
- **Integration Testing**: Test module combinations
- **Black-box Testing**: Based on inputs/outputs
- **White-box Testing**: Based on code structure
- **Coverage**: Data coverage (input ranges) vs code coverage (statements/branches)

## Key Takeaways

1. **Choose appropriate data structures** based on required operations and performance needs
2. **Understand trade-offs** between different implementations
3. **Master pointer manipulation** for dynamic data structures
4. **Apply Big-O analysis** to evaluate algorithm efficiency
5. **Use templates** for reusable, type-independent code
6. **Plan for testing and debugging** from the start of development

## Common Implementation Patterns

### Adding Elements
- **Arrays**: Check bounds, increment counter
- **Linked Lists**: Allocate node, update pointers

### Removing Elements
- **Arrays**: Shift elements or swap with last
- **Linked Lists**: Update pointers, deallocate memory

### Searching
- **Unsorted**: Linear search O(N)
- **Sorted Arrays**: Binary search O(log N)
- **Linked Lists**: Sequential only O(N)

### Memory Management
- **Static**: Fixed size at compile time
- **Dynamic**: Allocate/deallocate at runtime
- **Always pair** `new` with `delete`
- **Use destructors** for automatic cleanup

## Recursion

* **Static Binding** occurs at compile time
    * When a program is compiled, the compiler records every variable in a `symbol table` and assign it a memory address
    * After which the compiler replaces each reference with 
    ```cpp
    /*
    During compilation, totalroster = offcount + defcount; is translated into machine instructions: "Load value stored at 0002, load into value stored at 0003
    int totalroster, offcount, decount;
    */

    int main(){
        ...
        totalroster = offcount + defcount;
        std::cout << totalroster << std:endl;
    }
    ```
    * **Programming languages that only use static binding cannot support recursion**
* **Dynamic Binding** occurs at run time

* **Stack Frame** A block of memory to store important information such as local vars, parameters, and return address, when a function is called
    * Every functions creates a stack frame and after call is complete it will be dropped automatically
    * During **recursion**, each recursive call will add its own stack frame
    * The stack is LIFO, so their stack frames are nicely arranged one after another

* **Recursion Depth** is the number of recursive calls untill reaching its base case (e.g., 4 for Factorial(4))
