#include <iostream>
#include "./ListNode.h"

// Dequeue represents a double-ended queue
template<typename T> struct Dequeue {
private:
    ListNode<T> *tail, *head; // Pointers to the tail and head of the dequeue

public:
    // Constructor to initialize an empty dequeue
    Dequeue() {
        tail = head = nullptr; // Initialize tail and head pointers to null
    }

    // Enqueue an item at the front of the dequeue
    void enqueueFront(T item) {
        ListNode<T> *node = new ListNode<T>(item); // Create a new node with the given item

        if(empty()) { // If the dequeue is empty
            tail = head = node; // Set both tail and head to point to the new node
        }
        else {
            node->next = head; // Set the next pointer of the new node to the current head
            head->prev = node; // Set the previous pointer of the current head to the new node
            head = node; // Update the head pointer to the new node
        }
    }

    // Dequeue an item from the front of the dequeue
    T dequeueFront() {
        if(empty()) { // If the dequeue is empty
            throw std::runtime_error("Dequeue from an empty Dequeue"); // Throw an error
        }

        T item = front(); // Get the value of the front item

        if(head == tail) { // If there is only one node in the dequeue
            head = tail = nullptr; // Set both head and tail pointers to null
        }
        else {
            head = head->next; // Move the head pointer to the next node
            head->prev = nullptr; // Set the previous pointer of the new head to null
        }
        return item; // Return the dequeued item
    }

    // Get a reference to the front item without dequeuing it
    T& front() {
        if(empty()) { // If the dequeue is empty
            throw std::runtime_error("Front from an empty Dequeue"); // Throw an error
        }
        return head->value; // Return the value of the front item
    }

    // Enqueue an item at the back of the dequeue
    void enqueueBack(T item) {
        ListNode<T> *node = new ListNode<T>(item); // Create a new node with the given item

        if(empty()) { // If the dequeue is empty
            tail = head = node; // Set both tail and head to point to the new node
        }
        else {
            tail->next = node; // Set the next pointer of the current tail to the new node
            node->prev = tail; // Set the previous pointer of the new node to the current tail
            tail = node; // Update the tail pointer to the new node
        }
    }

    // Dequeue an item from the back of the dequeue
    T dequeueBack() {
        if(empty()) { // If the dequeue is empty
            throw std::runtime_error("Dequeue from an empty Dequeue"); // Throw an error
        }

        T item = back(); // Get the value of the back item

        if(head == tail) { // If there is only one node in the dequeue
            head = tail = nullptr; // Set both head and tail pointers to null
        }
        else {
            tail = tail->prev; // Move the tail pointer to the previous node
            tail->next = nullptr; // Set the next pointer of the new tail to null
        }
        return item; // Return the dequeued item
    }

    // Get a reference to the back item without dequeuing it
    T& back() {
        if(empty()) { // If the dequeue is empty
            throw std::runtime_error("Back from an empty Dequeue"); // Throw an error
        }
        return tail->value; // Return the value of the back item
    }

    // Check if the dequeue is empty
    int empty() {
        return tail == nullptr && head == nullptr; // Return true if both tail and head pointers are null
    }
};
