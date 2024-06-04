#ifndef MERGEABLE_HEAP_H
#define MERGEABLE_HEAP_H

#include <iostream>
using namespace std;

/**
 * @brief Node structure to represent each element in the linked list.
 */
struct Node {
    int key;    ///< The value stored in the node.
    Node* next; ///< Pointer to the next node in the list.
    
    /**
     * @brief Constructor to initialize a node with a given key.
     * @param k The key value.
     */
    Node(int k);
};

/**
 * @brief Class to represent a mergeable heap using linked lists.
 * 
 * This class provides operations to manage a mergeable heap,
 * including creation, insertion, finding the minimum, extracting
 * the minimum, merging heaps, and printing the heap.
 */
class MergeableHeap {
private:
    Node* head;   ///< Pointer to the head of the linked list representing the heap.
    bool isSorted;///< Flag indicating whether the list is sorted.

    /**
     * @brief Merges two sorted linked lists.
     * @param h1 Pointer to the head of the first list.
     * @param h2 Pointer to the head of the second list.
     * @return Pointer to the head of the merged list.
     * @note Time complexity: O(n + m), where n and m are the lengths of the two lists.
     *       Space complexity: O(n + m) due to recursive calls.
     */
    Node* mergeSorted(Node* h1, Node* h2);

    /**
     * @brief Merges two unsorted linked lists.
     * @param h1 Pointer to the head of the first list.
     * @param h2 Pointer to the head of the second list.
     * @return Pointer to the head of the merged list.
     * @note Time complexity: O(n), where n is the length of the first list.
     *       Space complexity: O(1).
     */
    Node* mergeUnsorted(Node* h1, Node* h2);

public:
    /**
     * @brief Constructor to initialize a mergeable heap.
     * @param sorted Flag indicating whether the heap should be sorted.
     */
    MergeableHeap(bool sorted);

    /**
     * @brief Initializes an empty heap.
     * @note Time complexity: O(1).
     *       Space complexity: O(1).
     */
    void makeHeap();

    /**
     * @brief Inserts a new key into the heap.
     * @param key The key value to insert.
     * @note Time complexity: O(n) for sorted insert, O(1) for unsorted insert, where n is the number of elements in the heap.
     *       Space complexity: O(1).
     */
    void insert(int key);

    /**
     * @brief Returns the minimum key from the heap.
     * @return The minimum key.
     * @throws runtime_error if the heap is empty.
     * @note Time complexity: O(1) for sorted heap, O(n) for unsorted heap, where n is the number of elements in the heap.
     *       Space complexity: O(1).
     */
    int minimum();

    /**
     * @brief Extracts and returns the minimum key from the heap.
     * @return The minimum key.
     * @throws runtime_error if the heap is empty.
     * @note Time complexity: O(1) for sorted heap, O(n) for unsorted heap, where n is the number of elements in the heap.
     *       Space complexity: O(1).
     */
    int extractMin();

    /**
     * @brief Merges another heap into this heap.
     * @param other The other heap to merge with this heap.
     * @note Time complexity: O(n + m) for sorted heaps, O(n) for unsorted heaps, where n and m are the lengths of the two heaps.
     *       Space complexity: O(1).
     */
    void unionHeaps(MergeableHeap& other);

    /**
     * @brief Prints the elements of the heap.
     * @note Time complexity: O(n), where n is the number of elements in the heap.
     *       Space complexity: O(1).
     */
    void printHeap();
};

#endif // MERGEABLE_HEAP_H
