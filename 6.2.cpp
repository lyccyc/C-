#include <iostream>
using namespace std;

class LinkedList
{
    public :
        class Node
        {
            public :
                Node() : next(nullptr), data(0) {}
                Node(int d) : next(nullptr), data(d) {}
                Node(Node *n) : next(n), data(0) {}
                Node(Node *n, int d) : next(n), data(d) {}
                int data ;
                Node *next ;
        } ;
        LinkedList() :head(nullptr) {}
        ~LinkedList() {
            while(head){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        //add data from the head of the linked list and then return true or false determining the data added or not. 
        bool addFromHead(int d) {
            //創建新的
            Node *newNode = new Node (d);
            if(!newNode)
                return false;
            //指向原來的
            newNode->next = head;
            //更新新的
            head= newNode;
            return true;
        }
        // add data from the tail of the linked list and then return true or false determining the data added or not
        bool addFromTail(int d) {
            Node *newNode = new Node(d);
            if (!newNode)
                return false;

            //如果陣列為空，指向新的
            if (!head) {
                head = newNode;
            } else { //找到最後一個
                Node *temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
            return true;
        }
        //remove the data from the head of the linked list and then return true of false determining the data deleted or not.
        bool removeFromHead() {
            //陣列為空，返回false
            if (!head)
                return false;

            //指向第一個
            Node *temp = head;
            //第一個指向下一個
            head = head->next;
            //刪除第一個
            delete temp;
            return true;
        }
        //remove the data from the tail of the linked list and then return true of false determining the data deleted or not.
        bool removeFromTail() {
            //陣列為空，返回false
            if (!head)
            return false;
            //刪除唯一一個
            if (!head->next) {
                delete head;
                head = nullptr;
            } else { //找到倒數第二個，刪除最後一個
                Node *temp = head;
                while (temp->next->next)
                    temp = temp->next;
                delete temp->next;
                temp->next = nullptr;
            }
            return true;
        }
        friend ostream &operator<<(ostream &o, LinkedList *link) {
            o << '{';
            Node* temp = link->head;
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
    protected :
        Node *head ;
} ;


/*int main() {
    LinkedList ll;
    ll.addFromHead(4);
    ll.addFromTail(5);
    cout << &ll;

    ll.removeFromHead();
    cout << &ll;

    ll.removeFromTail();
    cout << &ll;

    return 0;
}*/