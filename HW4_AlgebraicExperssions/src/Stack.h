//
// Barış Tan Ünal
// 220003617
// 29.12.2021
//

#include <string>
using namespace std;

#ifndef HOMEWORK4_STACK_H
#define HOMEWORK4_STACK_H


typedef string StackItemType;

class Stack{

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        StackItemType item;       // a data item on the stack
        StackNode* next;          // pointer to next node
    };

    StackNode* topPtr;            // pointer to first node in the stack
};


#endif //HOMEWORK4_STACK_H
