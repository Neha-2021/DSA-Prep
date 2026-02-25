/*
Problem Statement: Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list 
and return the updated linked list.

Input: 0->1->2, val = 5 
Output: 5->0->1->2


*/

#include <iostream>
#include <algorithm>
using namespace std;

struct LinkedList 
{
    public:
    int data;
    LinkedList* next;

    public:
    LinkedList(int data1, LinkedList* next1) {
        data = data1;
        next = next1;
    }

    public:
    LinkedList(int data1) {
        data = data1;
    }
};

LinkedList* convertArrayToLinkedList(vector<int> &arr) {
    LinkedList* head = new LinkedList(arr[0]);
    LinkedList* mover = head;

    for(int i=1; i<arr.size(); i++) {
        LinkedList* temp = new LinkedList(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

LinkedList* insertAtHead(LinkedList* head, int val) {
    LinkedList* newNode = new LinkedList(val, head);
    return newNode;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    LinkedList* head = convertArrayToLinkedList(arr);
    cout << "Array is converted to LL, head = " << head->data << "\n"; 

    LinkedList* newHead = insertAtHead(head, 1);
    cout << "New head after insertion = " << newHead->data << "\n";
}