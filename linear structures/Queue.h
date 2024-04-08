#include <iostream>
#include "./ListNode.h"

// Queue represents a FIFO (First In First Out) queue
template<typename T> struct Queue {
private:
    ListNode<T> *tail, *head; // Pointers to the tail and head of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        tail = head = nullptr; // Initialize tail and head pointers to null
    }

    // Enqueue an item at the back of the queue
    void enqueue(T item) {
        ListNode<T> *node = new ListNode<T>(item); // Create a new node with the given item

        if(empty()) { // If the queue is empty
            tail = head = node; // Set both tail and head to point to the new node
        }
        else {
            node->prev = tail; // Set the prev pointer of the new node to the current tail
            tail->next = node; // Set the next pointer of the current tail to the new node
            tail = node; // Update the tail pointer to the new node
        }
    }

    // Dequeue an item from the front of the queue
    T dequeue() {
        if(empty()) { // If the queue is empty
            throw std::runtime_error("Dequeue from an empty Queue"); // Throw an error
        }

        T item = front(); // Get the value of the front item

        if(head == tail) { // If there is only one node in the queue
            head = tail = nullptr; // Set both head and tail pointers to null
        }
        else {
            head = head->next; // Move the head pointer to the next node
            head->prev = nullptr; // Set the prev pointer of the new head to null
        }
        return item; // Return the dequeued item
    }

    // Get a reference to the front item without dequeuing it
    T& front() {
        if(empty()) { // If the queue is empty
            throw std::runtime_error("Front from an empty Queue"); // Throw an error
        }
        return head->value; // Return the value of the front item
    }

    // Check if the queue is empty
    int empty() {
        return tail == nullptr && head == nullptr; // Return true if both tail and head pointers are null
    }
};
