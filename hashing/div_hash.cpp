#include <iostream>
#include <vector>

// Step 1: Define the key-value pair structure (Node)
struct Node {
    int key;
    int value;
    Node(int k, int v) : key(k), value(v) {}
};

class HashTable {
private:
    int tableSize;                   // Size of the hash table (number of buckets)
    std::vector<std::vector<Node>> buckets;  // Vector of vectors to hold the buckets (chaining)

public:
    // Step 2: Constructor to initialize the hash table with a given size
    HashTable(int size) : tableSize(size), buckets(size) {}

    // Step 3: Hash function using the division method
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Step 4: Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        buckets[index].push_back(Node(key, value));
    }

    // Retrieve the value associated with a given key
    int get(int key) {
        int index = hashFunction(key);
        for (const auto& node : buckets[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return -1; // Return -1 if the key is not found
    }

    // Delete a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->key == key) {
                buckets[index].erase(it);
                break;
            }
        }
    }
};

int main() {
    // Creating a hash table with 10 buckets
    HashTable hashTable(10);

    // Inserting key-value pairs
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);
    hashTable.insert(11, 1100); // Should go to the same bucket as 1 (collision handling)

    // Retrieving values
    std::cout << "Value for key 1: " << hashTable.get(1) << std::endl;
    std::cout << "Value for key 2: " << hashTable.get(2) << std::endl;
    std::cout << "Value for key 11: " << hashTable.get(11) << std::endl;

    // Removing a key-value pair
    hashTable.remove(2);
    std::cout << "Value for key 2 after removal: " << hashTable.get(2) << std::endl;

    return 0;
}
