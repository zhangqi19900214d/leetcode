/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class MinStack {
    list<int64_t> value_stack;
    list<int64_t> min_stack;
    int64_t min_value;

public:
    /** initialize your data structure here. */
    MinStack() {
        min_value = INT64_MAX;
    }

    void push(int x)
    {
        if (x < min_value)
        {
            min_value = x;
        }

        min_stack.push_front(min_value);
        value_stack.push_front(x);
    }

    void pop()
    {
        value_stack.pop_front();
        min_stack.pop_front();
        
        if (!min_stack.empty())
        {
            min_value = min_stack.front();
        }
        else
        {
            min_value = INT64_MAX;
        }
    }

    int top()
    {
        return value_stack.front();
    }

    int getMin()
    {
        return min_stack.front();
    }
};

int main()
{
    MinStack minStack;
    //minStack.push(-2);
    //minStack.push(0);
    //minStack.push(-3);
    //cout << minStack.getMin() << endl;   //--> Returns - 3.
    //minStack.pop();      //
    //cout << minStack.top() << endl;;      //--> Returns 0.
    //minStack.getMin();   //--> Returns - 2.

    //["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
    //[[], [2147483646], [2147483646], [2147483647], [], [], [], [], [], [], [2147483647], [], [], [-2147483648], [], [], [], []]
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);

    minStack.top();
    minStack.pop();

    minStack.getMin();
    minStack.pop();

    minStack.getMin();
}