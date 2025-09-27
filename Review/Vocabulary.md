# CSE 302 Data Structures - Vocabulary List

## Software Engineering Terms

**Abstract Data Type (ADT)** - A conceptual definition of a data type based on its behaviors and operations, independent of implementation

**Abstraction** - A simplified model of a complex system focusing only on essential details for a specific audience

**Agile Model** - Software development approach using iterative cycles with frequent client collaboration and feedback

**Algorithm** - A logical sequence of discrete steps that describes a complete solution to a problem

**Assertion** - Logical propositions about what a program should do, used for verification

**Big-O Notation** - Mathematical notation describing how algorithm execution time scales with input size

**Binary Search** - O(log N) search algorithm that halves the search space each iteration (requires sorted data)

**Black-box Testing** - Testing based on inputs and outputs without knowledge of internal code structure

**Class** - An unstructured data type that groups data elements and operations, with private members by default

**Constructor** - Special member function automatically called when creating an object

**Data Encapsulation** - Process of hiding implementation details behind an interface

**Data Structure** - The actual physical implementation of an ADT

**Destructor** - Special member function that cleans up resources when an object goes out of scope

**Information Hiding** - Practice of keeping internal module details private from external access

**Linear Search** - O(N) search algorithm that checks each element sequentially

**Module** - Self-contained system subunit that performs a specific portion of work

**Postcondition** - Condition that will be true after an operation completes

**Precondition** - Condition that must be true before an operation is executed

**Regression Testing** - Testing performed after changes to ensure no new failures are introduced

**Software Specification** - Written document describing what a program does but not how

**Spiral Model** - Software development model emphasizing risk assessment and iterative refinement

**Stepwise Refinement** - Problem-solving approach breaking problems into stages (top-down, bottom-up)

**Struct** - Unstructured data type with public members by default, typically used as basic data containers

**Template** - C++ class or function written independently of specific data types using placeholders

**Unit Testing** - Testing individual program modules or functions in isolation

**Waterfall Model** - Linear, sequential software development approach

**White-box Testing** - Testing based on internal code structure (statements, branches, paths)

## Data Types and Structures

**Array** - Finite, fixed-size collection of ordered homogeneous elements with random access

**Circular Array** - Array implementation where indices wrap around using modulo arithmetic

**Circular Linked List** - Linked list where the last node points back to the first node

**Composite Data Type** - Data type storing a collection of individual components under one name

**Continuous Data** - Data that can take any value within a range (e.g., temperature, weight)

**Discrete Data** - Data that takes values from a specific, countable set (e.g., number of students)

**Doubly Linked List** - Linked list where each node has pointers to both next and previous nodes

**Dynamic Allocation** - Memory allocation at runtime using the heap

**Homogeneous** - All elements are of the same data type

**Interval Data** - Quantitative data where division is not meaningful (e.g., temperature in Fahrenheit)

**Key** - Attribute used to determine the order in sorted data structures

**Linked List** - Collection of nodes linked together using pointers

**Node** - Basic component of linked list containing data and pointer(s) to other nodes

**Nominal Data** - Qualitative data with no inherent order (e.g., colors, names)

**Ordinal Data** - Qualitative data with comparable levels (e.g., grades, rankings)

**Ratio Data** - Quantitative data where division is meaningful (e.g., weight, height)

**Record** - Finite collection of related elements (fields) accessed by named selectors

**Structured Data** - Composite data where organization affects access patterns

**Unstructured Data** - Composite data where components lack inherent organization

## Memory Management

**Delete Operator** - C++ operator that deallocates dynamically allocated memory

**Dereference Operator (*)** - Operator that returns the value at the memory address stored in a pointer

**Dynamic Memory** - Memory allocated at runtime that can be manually managed

**Garbage** - Dynamically allocated memory that can no longer be accessed

**Heap** - Section of memory reserved for dynamic allocation

**Lifetime** - Time during execution that an object occupies memory

**Memory Leak** - Situation where allocated memory is never released and becomes inaccessible

**New Operator** - C++ operator for dynamic memory allocation

**Pointer** - Variable that contains the memory address of another variable

**Reference Operator (&)** - Operator that returns the memory address of a variable

**Static Allocation** - Memory allocation at compile time

## List ADT Terms

**Accessor** - Observer function that returns a copy of data

**Constructor** - Function that creates new instances of an ADT

**Iterator** - Function that performs sequential actions on all elements

**Linear Relationship** - Every element except first has unique predecessor, every element except last has unique successor

**Observer** - Function that allows viewing the state of data without changing it

**Predicate** - Observer function that returns true or false (e.g., IsEmpty)

**Summary** - Observer function that returns information about the object as a whole

**Transformer** - Function that changes the data in a data structure

## Stack Terms

**LIFO** - Last In, First Out - stack ordering principle

**Peek/Top** - Stack operation that returns the top item without removing it

**Pop** - Stack operation that removes and returns the top item

**Push** - Stack operation that adds an item to the top

**Stack Frame** - Memory structure containing function call information (return address, local variables)

**Stack Overflow** - Error when trying to push onto a full stack

**Stack Underflow** - Error when trying to pop from an empty stack

## Queue Terms

**Circular Queue** - Queue implementation using circular array with front and rear pointers

**Dequeue** - Queue operation that removes and returns the front item

**Double-ended Queue** - Data structure allowing insertion/deletion at both ends

**Enqueue** - Queue operation that adds an item to the rear

**FIFO** - First In, First Out - queue ordering principle

**Fixed-Front Queue** - Array-based queue implementation where index 0 is always the front

**Floating Queue** - Array-based queue where both front and rear pointers can move

## Algorithm Complexity

**Best Case** - Minimum number of operations for an algorithm

**Constant Time O(1)** - Algorithm whose runtime doesn't change with input size

**Exponential Time** - Algorithm whose runtime grows exponentially with input size

**Linear Time O(N)** - Algorithm whose runtime grows proportionally with input size

**Logarithmic Time O(log N)** - Algorithm whose runtime grows logarithmically with input size

**Quadratic Time O(N²)** - Algorithm whose runtime grows quadratically with input size

**Worst Case** - Maximum number of operations for an algorithm

## C++ Specific Terms

**Arrow Operator (->)** - Operator to access member of object through pointer

**Exception** - Runtime error that can be caught and handled

**Namespace** - Feature that groups identifiers to prevent naming conflicts

**Overloading** - Having multiple functions with the same name but different signatures

**Pass by Reference** - Function parameter receives memory location, allowing modification

**Pass by Value** - Function parameter receives a copy, original cannot be modified

**Polymorphism** - Ability to selectively determine which version of a function to use

**Scope Resolution Operator (::)** - Operator indicating a function belongs to a class or namespace

**size_t** - Unsigned integer type preferred for storing size-related values

**sizeof** - Operator that returns the size of a variable or type in bytes

**Stream** - Flow of data, typically for input/output operations

**Template Function** - Function that works with template data types

**Try-Catch Block** - Exception handling mechanism in C++

## Data Analysis Terms

**Attribute** - Variable or characteristic that describes each data sample

**Dataset** - Collection of data samples

**Multivariate Analysis** - Analysis of relationships between multiple attributes

**Sample** - Individual data point in a dataset

**Supervised Analysis** - Analysis focused on a particular labeled attribute

**Univariate Analysis** - Analysis of the distribution of a single attribute

**Unsupervised Analysis** - Analysis exploring data without predefined labels

## Advanced Concepts

**Access Violation** - Error when program tries to read/write memory reserved by another process

**Capacity** - Total allocated memory space (vs. size which is actual elements used)

**Data Coverage** - Testing approach using wide range of inputs

**Edge Case** - Special scenario occurring at boundaries or limits of data structures

**Function Contract** - Definition of data types and behavior for function input/output

**Helper Function** - Function that handles specific part of another function to reduce code duplication

**Test Driver** - Program that automatically executes test plans by reading input files

**Trace** - Step-by-step examination of program execution state