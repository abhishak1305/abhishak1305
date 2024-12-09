// 1. Linear Probing
#include <iostream>
using namespace std;

class LinearProbingHashTable {
private:
    int *table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    LinearProbingHashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) { // Find the next available slot
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
        }
    }

    ~LinearProbingHashTable() {
        delete[] table;
    }
};

int main() {
    LinearProbingHashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.display();
    return 0;
}


// 2. Quadratic Probing
#include <iostream>
using namespace std;

class QuadraticProbingHashTable {
private:
    int *table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    QuadraticProbingHashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1) { // Quadratic probing
            i++;
        }
        table[(index + i * i) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
        }
    }

    ~QuadraticProbingHashTable() {
        delete[] table;
    }
};

int main() {
    QuadraticProbingHashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.display();
    return 0;
}

// Double hashing
#include <iostream>
using namespace std;

class DoubleHashingHashTable {
private:
    int *table;
    int size;

    int hashFunction1(int key) {
        return key % size;
    }

    int hashFunction2(int key) {
        return 7 - (key % 7); // A secondary hash function
    }

public:
    DoubleHashingHashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
        }
    }

    void insert(int key) {
        int index = hashFunction1(key);
        int i = 0;
        while (table[(index + i * hashFunction2(key)) % size] != -1) { // Double hashing
            i++;
        }
        table[(index + i * hashFunction2(key)) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
        }
    }

    ~DoubleHashingHashTable() {
        delete[] table;
    }
};

int main() {
    DoubleHashingHashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.display();
    return 0;
}

// 4. Mid-Square Hashing
#include <iostream>
using namespace std;

class MidSquareHashTable {
private:
    int *table;
    int size;

    int midSquareHashFunction(int key) {
        int square = key * key;
        int mid = (square / 10) % 100; // Extract the middle two digits
        return mid % size;
    }

public:
    MidSquareHashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
        }
    }

    void insert(int key) {
        int index = midSquareHashFunction(key);
        while (table[index] != -1) { // Linear probing for collision resolution
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
        }
    }

    ~MidSquareHashTable() {
        delete[] table;
    }
};

int main() {
    MidSquareHashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.display();
    return 0;
}

