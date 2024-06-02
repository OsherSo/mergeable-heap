#include <iostream>
#include "MergeableHeap.h"

using namespace std;

/**
 * @brief Main function to manage user interaction and perform operations on the mergeable heap.
 * 
 * This function initializes a mergeable heap based on user input (sorted/unsorted),
 * and allows the user to perform various operations like insert, find minimum,
 * extract minimum, union, and print the heap.
 * 
 * @return int Exit status.
 */
int main() {
    bool sorted;
    cout << "Enter 1 for sorted list implementation, 0 for unsorted: ";
    cin >> sorted;
    
    // Create a mergeable heap with the specified sorted/unsorted property
    MergeableHeap heap(sorted);
    heap.makeHeap();
    
    int choice, key;
    MergeableHeap otherHeap(sorted);
    
    do {
        // Display menu
        cout << "1. Insert\n2. Minimum\n3. Extract Min\n4. Union\n5. Print Heap\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Insert a new key into the heap
                cout << "Enter key to insert: ";
                cin >> key;
                heap.insert(key);
                break;
            case 2:
                // Display the minimum key from the heap
                try {
                    cout << "Minimum: " << heap.minimum() << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                // Extract and display the minimum key from the heap
                try {
                    cout << "Extracted Min: " << heap.extractMin() << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                // Perform union with another heap
                cout << "Creating another heap for union...\n";
                otherHeap.makeHeap();
                cout << "Enter keys to insert into the other heap (enter -1 to stop): ";
                while (true) {
                    cin >> key;
                    if (key == -1) break;
                    otherHeap.insert(key);
                }
                heap.unionHeaps(otherHeap);
                cout << "Union completed.\n";
                break;
            case 5:
                // Print the elements of the heap
                heap.printHeap();
                break;
            case 6:
                // Exit the program
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
