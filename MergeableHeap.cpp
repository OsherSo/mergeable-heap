#include "MergeableHeap.h"

/**
 * @brief Constructor to initialize a node with a given key.
 * @param k The key value.
 */
Node::Node(int k) : key(k), next(nullptr) {}

/**
 * @brief Constructor to initialize a mergeable heap.
 * @param sorted Flag indicating whether the heap should be sorted.
 */
MergeableHeap::MergeableHeap(bool sorted) : head(nullptr), isSorted(sorted) {}

/**
 * @brief Merges two sorted linked lists.
 * @param h1 Pointer to the head of the first list.
 * @param h2 Pointer to the head of the second list.
 * @return Pointer to the head of the merged list.
 * @note Time complexity: O(n + m), where n and m are the lengths of the two lists.
 *       Space complexity: O(n + m) due to recursive calls.
 */
Node* MergeableHeap::mergeSorted(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    
    if (h1->key <= h2->key) {
        h1->next = mergeSorted(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeSorted(h1, h2->next);
        return h2;
    }
}

/**
 * @brief Merges two unsorted linked lists.
 * @param h1 Pointer to the head of the first list.
 * @param h2 Pointer to the head of the second list.
 * @return Pointer to the head of the merged list.
 * @note Time complexity: O(n), where n is the length of the first list.
 *       Space complexity: O(1).
 */
Node* MergeableHeap::mergeUnsorted(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    
    Node* temp = h1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = h2;
    return h1;
}

/**
 * @brief Initializes an empty heap.
 * @note Time complexity: O(1).
 *       Space complexity: O(1).
 */
void MergeableHeap::makeHeap() {
    head = nullptr;
}

/**
 * @brief Inserts a new key into the heap.
 * @param key The key value to insert.
 * @note Time complexity: O(n) for sorted insert, O(1) for unsorted insert, where n is the number of elements in the heap.
 *       Space complexity: O(1).
 */
void MergeableHeap::insert(int key) {
    Node* newNode = new Node(key);
    if (isSorted) {
        if (!head || head->key >= key) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->key < key) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    } else {
        newNode->next = head;
        head = newNode;
    }
}

/**
 * @brief Returns the minimum key from the heap.
 * @return The minimum key.
 * @throws runtime_error if the heap is empty.
 * @note Time complexity: O(1) for sorted heap, O(n) for unsorted heap, where n is the number of elements in the heap.
 *       Space complexity: O(1).
 */
int MergeableHeap::minimum() {
    if (!head) throw runtime_error("Heap is empty");
    if (isSorted) return head->key;
    
    int minVal = head->key;
    Node* current = head->next;
    while (current) {
        if (current->key < minVal) minVal = current->key;
        current = current->next;
    }
    return minVal;
}

/**
 * @brief Extracts and returns the minimum key from the heap.
 * @return The minimum key.
 * @throws runtime_error if the heap is empty.
 * @note Time complexity: O(1) for sorted heap, O(n) for unsorted heap, where n is the number of elements in the heap.
 *       Space complexity: O(1).
 */
int MergeableHeap::extractMin() {
    if (!head) throw runtime_error("Heap is empty");

    int minVal = 0;
    Node* minNode = head;
    Node* current = head;
    
    if (isSorted) {
        head = head->next;
        minVal = minNode->key;
        delete minNode;
        return minVal;
    } else {
        Node* minPrev = nullptr;
        minVal = head->key;
        while (current->next) {
            if (current->next->key < minVal) {
                minPrev = current;
                minNode = current->next;
                minVal = current->next->key;
            }
            current = current->next;
        }
        
        if (minNode == head) {
            head = head->next;
        } else {
            minPrev->next = minNode->next;
        }
        minVal = minNode->key;
        delete minNode;
        return minVal;
    }
}

/**
 * @brief Merges another heap into this heap.
 * @param other The other heap to merge with this heap.
 * @note Time complexity: O(n + m) for sorted heaps, O(n) for unsorted heaps, where n and m are the lengths of the two heaps.
 *       Space complexity: O(1).
 */
void MergeableHeap::unionHeaps(MergeableHeap& other) {
    if (isSorted) {
        head = mergeSorted(head, other.head);
    } else {
        head = mergeUnsorted(head, other.head);
    }
    other.head = nullptr;
}

/**
 * @brief Prints the elements of the heap.
 * @note Time complexity: O(n), where n is the number of elements in the heap.
 *       Space complexity: O(1).
 */
void MergeableHeap::printHeap() {
    Node* current = head;
    while (current) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}
