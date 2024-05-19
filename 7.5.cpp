#include <iostream>
#include <typeinfo> 

using namespace std;

int judge(Container* c) {
    if (dynamic_cast<Stack*>(c) != nullptr) {
        return 1; // Stack
    } 
  	else if (dynamic_cast<PriorityQueue*>(c) != nullptr) {
        return 2; // PriorityQueue
    } 
  	else {
        return 0; // Unknown type
    }
}