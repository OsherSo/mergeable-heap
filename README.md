### README.md

# Mergeable Heap Implementation

## Overview

This project implements a mergeable heap using linked lists in C++. It supports the following operations:

- `makeHeap`: Creates an empty mergeable heap.
- `insert`: Inserts a new key into the heap.
- `minimum`: Returns the minimum key from the heap.
- `extractMin`: Extracts and returns the minimum key from the heap.
- `unionHeaps`: Merges another heap into this heap.
- `printHeap`: Prints the elements of the heap.

The heap can be implemented with either sorted or unsorted linked lists, based on user preference.

## Files

- `MergeableHeap.h`: Header file containing the declarations and documentation of the `Node` and `MergeableHeap` classes.
- `MergeableHeap.cpp`: Source file containing the implementations of the `Node` and `MergeableHeap` classes.
- `main.cpp`: Source file containing the main function that interacts with the user to perform heap operations.
- `Makefile`: File to automate the compilation and linking process.

## Prerequisites

- A C++ compiler (e.g., `g++`).
- Make utility.

## Compilation and Execution

### Using the Makefile

1. Open a terminal and navigate to the directory containing the project files.
2. Run the following command to compile the project:

   ```sh
   make
   ```

   This will compile the source files and create an executable named `mergeable_heap`.

3. To clean up the compiled files, run:
   ```sh
   make clean
   ```

### Running the Application

1. After compilation, run the executable:

   ```sh
   ./mergeable_heap
   ```

2. Follow the prompts to choose between a sorted or unsorted list implementation and perform various heap operations.

## Instructions for Use

1. **Choose Implementation**:

   - The application first asks if you want to use a sorted list or an unsorted list for the heap.
   - Enter `1` for a sorted list or `0` for an unsorted list.

2. **Perform Operations**:

   - You will be presented with a menu of operations:
     ```
     1. Insert
     2. Minimum
     3. Extract Min
     4. Union
     5. Print Heap
     6. Exit
     ```
   - Enter the number corresponding to the desired operation.

3. **Insert Operation**:

   - When prompted, enter the key to insert into the heap.

4. **Minimum Operation**:

   - The application will display the minimum key in the heap.

5. **Extract Min Operation**:

   - The application will extract and display the minimum key from the heap.

6. **Union Operation**:

   - The application will prompt you to create another heap for the union operation.
   - Enter the keys to insert into the second heap, ending with `-1`.
   - The two heaps will be merged, and the second heap will be cleared.

7. **Print Heap Operation**:

   - The application will print all the elements of the heap.

8. **Exit Operation**:
   - Enter `6` to exit the application.

## Example Usage

```
Enter 1 for sorted list implementation, 0 for unsorted: 1
1. Insert
2. Minimum
3. Extract Min
4. Union
5. Print Heap
6. Exit
Enter your choice: 1
Enter key to insert: 10
1. Insert
2. Minimum
3. Extract Min
4. Union
5. Print Heap
6. Exit
Enter your choice: 1
Enter key to insert: 5
1. Insert
2. Minimum
3. Extract Min
4. Union
5. Print Heap
6. Exit
Enter your choice: 2
Minimum: 5
1. Insert
2. Minimum
3. Extract Min
4. Union
5. Print Heap
6. Exit
Enter your choice: 6
```

## Documentation

For detailed information about the implementation and time complexity analysis, refer to the documentation within the `MergeableHeap.h`, `MergeableHeap.cpp`, and `main.cpp` files. Each function and class is documented to explain its purpose and usage.

## Contact

If you have any questions or need further assistance, please contact the project author.

---

This README provides a comprehensive guide to understanding, compiling, and using the mergeable heap application.
