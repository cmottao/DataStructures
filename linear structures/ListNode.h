// ListNode represents a node in the Queue and Dequeue
template<typename T> struct ListNode {
public:
    ListNode<T> *prev, *next; // Pointers to the previous and next nodes
    T value; // Value stored in the node

    // Constructor to initialize the node with a given value
    ListNode(T _value) {
        prev = next = nullptr; // Initialize prev and next pointers to null
        value = _value; // Set the value of the node
    }
};