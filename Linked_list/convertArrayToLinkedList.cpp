#include <iostream>
#include <algorithm>
using namespace std;

struct LinkedList 
{
    public:
    string data;
    LinkedList* next;

    public:
    LinkedList(string data1, LinkedList* next1) {
        data = data1;
        next = next1;
    }

    public:
    LinkedList(string data1) {
        data = data1;
    }
};

LinkedList* convertArrayToLinkedList(vector<string> &arr) {
    LinkedList* head = new LinkedList(arr[0]);
    LinkedList* mover = head;

    for(int i=1; i<arr.size(); i++) {
        LinkedList* temp = new LinkedList(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<string> arr = {"Neha", "Vishnu", "Vishal"};
    LinkedList* head = convertArrayToLinkedList(arr);
    cout << "Convert array to LL, head = " << head->data << "\n";    
}