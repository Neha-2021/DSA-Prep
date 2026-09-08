/*
Implement Queue Using Array

Problem Statement: Implement a First-In-First-Out (FIFO) queue using an array. 
The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Example 1:
Input:
 
["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]  
[[], [5], [10], [], [], []]  
Output:
 [null, null, null, 5, 5, false]  
Explanation:
  
ArrayQueue queue = new ArrayQueue();  
- queue.push(5);  
- queue.push(10);  
- queue.peek(); // returns 5  
- queue.pop(); // returns 5  
- queue.isEmpty(); // returns false  
*/

#include <iostream>
#include <algorithm>
using namespace std;

class ArrayQueue {
public:
    vector<int> nums;
    ArrayQueue() {
    }
    
    void push(int x) {
        nums.push_back(x);
    }
    
    int pop() {
        int currentTop = nums[0];
        nums.erase(nums.begin());
        return currentTop;
    }
    
    int peek() {
        return nums[0];
    }
    
    bool isEmpty() {
        return nums.empty();
    }
};

int main() {
    ArrayQueue q;

    cout << "Is queue empty? " << q.isEmpty() << endl;


    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek element: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Peek element: " << q.peek() << endl;

    cout << "Is queue empty? " << q.isEmpty() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Peek element: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;

    cout << "Is queue empty? " << q.isEmpty() << endl;

    return 0;
}