/*
push: insert an element。
pop: delete an element，throw a std::out_of_range exception if there are no element。
top: return the element that will be delete next，throw a std::out_of_range exception if there are no element。
empty: if there are no element then return true, otherwise return false。
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

//Stack will always delete the data that last inserted
//PriorityQueue will always delete the data that hold the maximum value.


class Container {
public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual bool empty() const = 0;
};

class Stack : public Container {
private:
    vector<int> data;
public:
    void push(int value) override {
        data.push_back(value); //加到最後一個元素後面
    }

    void pop() override {
        if (empty())
            throw out_of_range("Stack is empty");
        data.pop_back(); //刪除最後一個元素
    }

    int top() const override {
        if (empty())
            throw out_of_range("Stack is empty");
        return data.back(); //回傳最尾元素的值
    }

    bool empty() const override {
        return data.empty();
    }
};

class PriorityQueue : public Container {
private:
    vector<int> data;
public:
    void push(int value) override {
        data.push_back(value);
        push_heap(data.begin(), data.end());
    }

    void pop() override {
        if (empty())
            throw out_of_range("PriorityQueue is empty");
        pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    int top() const override {
        if (empty())
            throw out_of_range("PriorityQueue is empty");
        return data.front();
    }

    bool empty() const override {
        return data.empty();
    }
};


