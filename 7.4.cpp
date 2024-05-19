#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

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
        data.push_back(value);
    }

    void pop() override {
        if (empty())
            throw out_of_range("Stack is empty");
        data.pop_back();
    }

    int top() const override {
        if (empty())
            throw out_of_range("Stack is empty");
        return data.back();
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


