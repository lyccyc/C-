#include <iostream>

using namespace std;

template<class T>
class Set
{
  public:
    //Create a default constructor to make the set empty.
    Set() : count(0) {}
    // Copy constructor
    Set(const Set<T>& other) : count(other.count) { 
        for (int i = 0; i < other.count; ++i) {
            element[i] = other.element[i];
        }
    }
    // Add element to the set
    template<class U>
    int add(const U& val) { 
        for (int i = 0; i < count; ++i) {
            if (element[i] == val) // Check if element already exists
                return 0;
        }
        if (count < 100) {
            element[count++] = val;
            return 1;
        } else {
            return -1; // Set is full
        }
    }
    // Add elements into the set
    int add(const Set<T>& otherSet) { 
        int added = 0;
        for (int i = 0; i < otherSet.count; ++i) {
            added += add(otherSet.element[i]);
        }
        return added;
    }

  	void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        cout<<element[j]<<" ";
    }
  private:
  	T element[100];
  	int count;
};

/*int main() {
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

    std::cout << "Elements added from set2 to set1: " << set1.add(set2) << std::endl;
    set1.display(); // Output: 1 2 3 4 5

    return 0;
}*/