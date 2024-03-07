#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

template <typename T>
class HashTable {
private:
    struct Node {
        T key;
        Node* next;
        Node(T k) : key(k), next(nullptr) {}
    };

    // Hàm băm
    size_t hashFunction(T key) {
        double A = (std::sqrt(5) - 1) / 2;
        return static_cast<size_t>(floor(tableSize * (key * A - floor(key * A))));
    }

    Node** table;
    size_t tableSize;
    std::ofstream outputFile;
    size_t deletedCollisions;
    bool collisionDetected; // Cờ biểu thị xung đột trong quá trình insert
    bool searchCollisionDetected; // Cờ biểu thị xung đột trong quá trình search

public:
    HashTable(size_t m, std::string& outputFileName);       // constructor 
    ~HashTable();                                           // destructor
    void insert(T key);                                     // insert function
    void search(T key);                                     // search function
};


#endif // !1



