#include <iostream>

// Stack represents a basic LIFO (Last In First Out) stack
template<typename T> struct Stack {
private:
    int capacity, current; // Capacity of the stack and current number of elements
    T *data; // Pointer to the dynamic array

public:
    // Constructor to initialize an empty stack with initial capacity 1
    Stack() {
        current = 0; // Initialize current number of elements to 0
        capacity = 1; // Initialize capacity to 1
        data = new T[capacity]; // Allocate memory for the dynamic array
    }

    // Destructor to deallocate memory
    ~Stack() {
        delete[] data; // Free memory allocated for the dynamic array
    }

    // Push an item onto the top of the stack
    void push(T item) {
        if(capacity == current) { // If the stack is full
            capacity *= 2; // Double the capacity
            T *temporaryData = new T[capacity]; // Create a new array with the updated capacity

            // Copy elements from the old array to the new array
            for(int i = 0; i < current; i++) {
                temporaryData[i] = data[i];
            }

            delete[] data; // Free memory allocated for the old array
            data = temporaryData; // Update the pointer to the new array
        }
        data[current++] = item; // Add the new item to the top of the stack
    }

    // Pop the top item off the stack
    void pop() {
        if(empty()) { // If the stack is empty
            throw std::runtime_error("Pop from an empty Stack"); // Throw an error
        }
        current--; // Decrement the current number of elements
    }

    // Return a reference to the top item of the stack
    T& top() {
        if(empty()) { // If the stack is empty
            throw std::runtime_error("Top from an empty Stack"); // Throw an error
        }
        return data[current - 1]; // Return a reference to the top item
    }

    // Return the number of elements in the stack
    int size() {
        return current; // Return the current number of elements
    }

    // Check if the stack is empty
    int empty() {
        return current == 0; // Return true if the current number of elements is 0
    }
};
