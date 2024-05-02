#include <iostream>

using namespace std;

class LinkedList
{
public:
    class Node
    {
    public:
        Node() : next(nullptr), data(0) {}
        Node(int d) : next(nullptr), data(d) {}
        Node(Node *n) : next(n), data(0) {}
        Node(Node *n, int d) : next(n), data(d) {}
        int data;
        Node *next;
    };

    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool addFromHead(int d) {
        Node *newNode = new Node(d);
        if (!newNode)
            return false;

        newNode->next = head;
        head = newNode;
        return true;
    }

    bool addFromTail(int d) {
        Node *newNode = new Node(d);
        if (!newNode)
            return false;

        if (!head) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        return true;
    }

    bool removeFromHead() {
        if (!head)
            return false;

        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool removeFromTail() {
        if (!head)
            return false;

        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next->next)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        return true;
    }

    friend ostream &operator<<(ostream &o, const LinkedList &l) {
        o << '{';
        Node *temp = l.head;
        while (temp) {
            o << temp->data;
            if (temp->next)
                o << ", ";
            temp = temp->next;
        }
        o << "}\n";
        return o;
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

protected:
    Node *head;
};

int main() {
    LinkedList ll;
    ll.addFromHead(4);
    ll.addFromTail(5);
    cout << &ll;

    ll.removeFromHead();
    cout << &ll;

    ll.removeFromTail();
    cout << &ll;

    return 0;
}
