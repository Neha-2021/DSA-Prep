/*
Implement Stack using Arrays
Implement a Last-In-First-Out (LIFO) stack using an array. 
The implemented stack should support the following operations: push, pop, peek, and isEmpty.
You will be provided two arrays operations which contains what operation need to perform 
and nums which contains the values corresponding to the operations.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Example 1

Input: operations = ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
nums = [[], [5], [10], [], [], []]
Output: [null, null, null, 10, 10, false]

Explanation:
ArrayStack stack = new ArrayStack();
stack.push(5);
stack.push(10);
stack.top(); // returns 10
stack.pop(); // returns 10
stack.isEmpty(); // returns false

Example 2

Input: operations = ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]
nums = [[], [], [1], [], []]
Output: [null, true, null, 1, true]

Explanation: 
ArrayStack stack = new ArrayStack();
stack.push(1);
stack.pop(); // returns 1
stack.isEmpty(); // returns true
*/

#include <iostream>
#include <algorithm>
using namespace std;

class ArrayStack {
public:
    vector<int> nums;
    int topEle = 0;
    ArrayStack() {
    }
    
    void push(int x) {
        nums.push_back(x);
        topEle = nums.size()-1;
    }
    
    int pop() {
        int currentTop = nums[topEle];
        topEle -= 1;
        nums.pop_back();
        return currentTop;
    }
    
    int top() {
        return nums[topEle];
    }
    
    bool isEmpty() {
        return nums.empty();
    }
};

int main() {
    ArrayStack st;

    cout << "Is stack empty? " << st.isEmpty() << endl;


    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Top element: " << st.top() << endl;

    cout << "Is stack empty? " << st.isEmpty() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Is stack empty? " << st.isEmpty() << endl;

    return 0;
}