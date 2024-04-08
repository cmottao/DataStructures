#include <iostream>
#include <functional>

// Compare functions for max and min heap
auto maxCompare = [](int a, int b) { // For max heap
    return a > b; 
};

auto minCompare = [](int a, int b) { // For min heap
    return a < b; 
}; 

// Heap represents a binary heap
struct Heap {
private:
    std::function<bool(int, int)> compare; // Function pointer for comparison
    int capacity, current; // Capacity of the heap and current number of items
    int *data; // Array to store heap items

    // Calculate the index of the parent node of a given index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Calculate the index of the left child node of a given index
    int left(int i) {
        return (2 * i) + 1;
    }

    // Calculate the index of the right child node of a given index
    int right(int i) {
        return (2 * i) + 2;
    }

    // Move a node up in the heap until it satisfies the heap property
    void siftUp(int i) {
        // Swap the node with its parent if necessary
        while(i > 0 && compare(data[i], data[parent(i)])) {
            std::swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

    // Move a node down in the heap until it satisfies the heap property
    void siftDown(int i) {
        int extreme = i;

        // Check if the left child is smaller or larger than the current node
        if(left(i) < current && compare(data[left(i)], data[extreme])) {
            extreme = left(i);
        }
        // Check if the right child is smaller or larger than the current node
        if(right(i) < current && compare(data[right(i)], data[extreme])) {
            extreme = right(i);
        }

        // If the extreme node is not the current node, swap them and continue sifting down
        if(i != extreme) {
            std::swap(data[i], data[extreme]);
            siftDown(extreme);
        }
    }

public:
    // Constructor to initialize the heap with capacity and comparison function
    Heap(int _capacity, std::function<bool(int, int)> _compare) {
        current = 0; // Initialize current number of elements to 0
        capacity = _capacity; // Set the capacity
        data = new int[capacity]; // Initialize array with the given capacity
        compare = _compare; // Set the comparison function
    }

    // Destructor to deallocate memory
    ~Heap() {
        delete[] data;
    }

    // Insert an item into the heap while maintaining heap property
    void insert(int item) {
        if(capacity == current) { // If the heap is full
            throw std::runtime_error("The Heap is full"); // Throw an error
        }
        data[current] = item; // Add the new item
        siftUp(current++); // Move the inserted item up the heap if necessary
    }

    // Extract and return the top item while maintaining heap property
    int extractTop() {
        if(empty()) { // If the heap is empty
            throw std::runtime_error("ExtractTop from an empty Heap"); // Throw an error
        }
        int top = data[0]; // Get the top item
        data[0] = data[current-- - 1]; // Replace the top item with the last item
        siftDown(0); // Restore the heap property by sifting down the new top item
        return top; // Return the top item
    }

    // Return the top item without removing it
    int top() {
        if(empty()) { // If the heap is empty
            throw std::runtime_error("Top from an empty Heap"); // Throw an error
        }
        return data[0]; // Return the top item
    }

    // Check if the heap is empty
    int empty() {
        return current == 0; // Return true if the current number of items is 0
    }
};