#include <iostream>

// UnionFind represents a Union-Find Disjint Set
struct UnionFind {
private:
    int *rank, *parent, *setSize; // Arrays to store rank, parent, and size of sets

public:
    // Constructor to initialize the Union-Find data structure with given size
    UnionFind(int size) {
        // Initialize arrays with given size
        rank = new int[size]; 
        parent = new int[size];
        setSize = new int[size];

        // Initialize each element as a separate set with size 1
        for(int i = 0; i < size; i++) {
            rank[i] = 0;
            parent[i] = i;
            setSize[i] = 1;
        }
    }

    // Destructor to deallocate memory
    ~UnionFind() {
        delete[] rank, parent, setSize;
    }

    // Find the set representative (parent) of the element i
    int findSet(int i) {
        // If the element is its own parent, return it
        if(parent[i] == i) {
            return i;
        }
        // Path compression: Set the parent of i to its representative
        return parent[i] = findSet(parent[i]);
    }

    // Merge the sets containing elements i and j
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j); // Find the representatives of i and j

        if(x != y) { // If i and j belong to different sets
            if(rank[x] > rank[y]) { // Union by rank: Attach the smaller tree to the larger tree
                std::swap(x, y);
            }
            parent[x] = y; // Set the parent of smaller tree's representative to larger tree's representative

            if(rank[x] == rank[y]) { // If both trees have the same rank
                rank[y]++; // Increment rank of the resulting tree
            }
            setSize[y] += setSize[x]; // Update the size of the resulting set
        }
    }

    // Get the size of the set containing element i
    int sizeOfSet(int i) {
        return setSize[findSet(i)]; // Find representative and return the size of its set
    }
};
