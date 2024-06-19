#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
public:
    class Node
    {
    public:
        Node() : next(nullptr), data(T()) {}
        Node(T d) : next(nullptr), data(d) {}
        Node(Node *n) : next(n), data(T()) {}
        Node(Node *n, T d) : next(n), data(d) {}
        T data;
        Node *next;
    };

    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool addFromHead(T d) {
        Node *newNode = new Node(d);
        if (!newNode) return false;
        newNode->next = head;
        head = newNode;
        return true;
    }

    bool addFromTail(T d) {
        Node *newNode = new Node(d);
        if (!newNode) return false;

        if (!head) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        return true;
    }

    bool removeFromHead() {
        if (!head) return false;
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool removeFromTail() {
        if (!head) return false;
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        return true;
    }

    size_t getSize() const {
        size_t size = 0;
        Node *temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    int searchData(T d) const {
        Node *temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == d) return index;
            temp = temp->next;
            index++;
        }
        return -1; // not found
    }

    T operator[](int i) const {
        Node *temp = head;
        int index = 0;
        while (temp) {
            if (index == i) return temp->data;
            temp = temp->next;
            index++;
        }
        throw out_of_range("Index out of range");
    }

    friend ostream &operator<<(ostream &o, const LinkedList *l) {
        o << '{';
        Node* temp = l->head;
        while (temp) {
            o << temp->data;
            if (temp->next) o << ", ";
            temp = temp->next;
        }
        o << "}\n";
        return o;
    }

protected:
    Node *head;
};

template<class T>
class Set : private LinkedList<T>
{
public:
    Set<T>() : LinkedList<T>() {}
    
    bool addElement(T d) {
        if (this->searchData(d) == -1) { // 確保唯一性
            return this->addFromTail(d);
        }
        return false;
    }
    //升序回傳
    friend ostream &operator<<(ostream &o, Set<T> *s) {
        if (s->getSize() == 0) {
            o << "{}\n";
        } else {
            o << '{';
            typename LinkedList<T>::Node* temp = s->head;
            while (temp) {
                o << temp->data;
                if (temp->next) o << ", ";
                temp = temp->next;
            }
            o << "}\n";
        }
        return o;
    }
    //聯集
    Set<T>* operator+(Set<T> *s) {
        Set<T>* result = new Set<T>();
        for (size_t i = 0; i < this->getSize(); i++) {
            result->addElement((*this)[i]);
        }
        for (size_t i = 0; i < s->getSize(); i++) {
            result->addElement((*s)[i]);
        }
        return result;
    }
    //不同的
    Set<T>* operator-(Set<T> *s) {
        Set<T>* result = new Set<T>();
        for (size_t i = 0; i < this->getSize(); i++) {
            if (s->searchData((*this)[i]) == -1) {
                result->addElement((*this)[i]);
            }
        }
        return result;
    }
    //交集
    Set<T>* operator*(Set<T> *s) {
        Set<T>* result = new Set<T>();
        for (size_t i = 0; i < this->getSize(); i++) {
            if (s->searchData((*this)[i]) != -1) {
                result->addElement((*this)[i]);
            }
        }
        return result;
    }
};