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

    //尋找交集
    bool contains(const T& val) const { 
        for (int i = 0; i < count; ++i) {
            if (element[i] == val)
                return true;
        }
        return false;
    }
    
    Set<T>
    operator+(const Set<T>& other) const{
        Set<T> result(*this); //初始化
        result.add(other);    //把other內的元素加到result
        return result;        //回傳
    }

    Set<T>
    operator-(const Set<T>& other) const{
        Set<T> result;      //創建新的集合  
        for (int i = 0; i < count; ++i) {
            if (other.contains(element[i])) {
                result.add(element[i]);
            }
        }
        return result;
    }
  private:
  	T element[100];
  	int count;
};