/*
Problem Statement: Given the head of a linked list, print the length of the linked list.

Examples
Input: 0->1->2 
Output: 3

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

int determineLengthOfLinkedList(LinkedList* head) {
    int count = 0;
    LinkedList* temp = head;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    LinkedList* head = convertArrayToLinkedList(arr);
    cout << "Convert array to LL, head = " << head->data << "\n"; 
    
    cout << "Length of linked list is = " << determineLengthOfLinkedList(head) << "\n";
}