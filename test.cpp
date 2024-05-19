#include <iostream>
#include <algorithm> // for std::sort

template<class T>
class Set {
public:
    Set() : count(0) {} // Default constructor to make the set empty
    Set(const Set<T>& other) : count(other.count) { // Copy constructor
        for (int i = 0; i < other.count; ++i) {
            element[i] = other.element[i];
        }
    }

    template<class U>
    int add(const U& val) { // Add element to the set
        for (int i = 0; i < count; ++i) {
            if (element[i] == val) // Check if element already exists
                return 0;
        }
        if (count < 100) {
            element[count++] = val;
            std::sort(element, element + count); // Sort elements
            return 1;
        } else {
            return -1; // Set is full
        }
    }

    int add(const Set<T>& otherSet) { // Add elements from another set
        int added = 0;
        for (int i = 0; i < otherSet.count; ++i) {
            added += add(otherSet.element[i]);
        }
        return added;
    }

    Set<T> operator+(const Set<T>& otherSet) const { // Union operation
        Set<T> result(*this);
        result.add(otherSet);
        return result;
    }

    Set<T> operator-(const Set<T>& otherSet) const { // Intersection operation
        Set<T> result;
        for (int i = 0; i < count; ++i) {
            if (otherSet.contains(element[i])) {
                result.add(element[i]);
            }
        }
        return result;
    }

    bool contains(const T& val) const { // Check if set contains the element
        for (int i = 0; i < count; ++i) {
            if (element[i] == val)
                return true;
        }
        return false;
    }

    void display() const { // Display elements in the set
        for (int i = 0; i < count; ++i) {
            std::cout << element[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T element[100];
    int count;
};

int main() {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    set1.add(2); // Adding duplicate element
    set1.display(); // Output: 1 2 3

    Set<int> set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);
    set2.display(); // Output: 3 4 5

    Set<int> unionSet = set1 + set2; // Union
    std::cout << "Union: ";
    unionSet.display(); // Output: 1 2 3 4 5

    Set<int> intersectSet = set1 - set2; // Intersection
    std::cout << "Intersection: ";
    intersectSet.display(); // Output: 3

    return 0;
}
