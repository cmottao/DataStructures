#include <iostream>

// Vector represents a dynamic array
template<typename T> struct Vector {
private:
    int capacity, current; // Capacity of the vector and current number of elements
    T *data; // Pointer to the dynamic array

public:
    // Constructor to initialize an empty vector with initial capacity 1
    Vector() {
        current = 0; // Initialize current number of elements to 0
        capacity = 1; // Initialize capacity to 1
        data = new T[capacity]; // Allocate memory for the dynamic array
    }

    // Destructor to deallocate memory
    ~Vector() {
        delete[] data; // Free memory allocated for the dynamic array
    }

    // Add an item to the end of the vector
    void push(T item) {
        if(capacity == current) { // If the vector is full
            capacity *= 2; // Double the capacity
            T *temporaryData = new T[capacity]; // Create a new array with the updated capacity

            // Copy elements from the old array to the new array
            for(int i = 0; i < current; i++) {
                temporaryData[i] = data[i];
            }

            delete[] data; // Free memory allocated for the old array
            data = temporaryData; // Update the pointer to the new array
        }
        data[current++] = item; // Add the new item to the end of the vector
    }

    // Remove the last item from the vector
    void pop() {
        if(empty()) { // If the vector is empty
            throw std::runtime_error("Pop from an empty Vector"); // Throw an error
        }
        current--; // Decrement the current number of elements
    }

    // Overloaded subscript operator to access elements by index
    T& operator[](int index) {
        if(index < 0 || index >= current) { // If the index is out of range
            throw std::out_of_range("Index out of range"); // Throw an error
        }
        return data[index]; // Return a reference to the element at the specified index
    }

    // Return the number of elements in the vector
    int size() {
        return current; // Return the current number of elements
    }

    // Check if the vector is empty
    int empty() {
        return current == 0; // Return true if the current number of elements is 0
    }
};
