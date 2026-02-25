/*
Problem Statement: There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]


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

void deleteNode(LinkedList* node) {
    LinkedList* nextNode = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete nextNode;
}

void printNode(LinkedList* head) {
    LinkedList* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    LinkedList* head = convertArrayToLinkedList(arr);
    cout << "Array is converted to LL, head = " << head->data << "\n"; 
    cout << "LinkedList before deletion: \n";
    printNode(head);

    LinkedList* nodeToDelete = head->next->next;
    cout << "Node to delete = " << nodeToDelete->data << "\n";
    deleteNode(head->next->next);
    cout << "LinkedList after deletion: \n";
    printNode(head);
}