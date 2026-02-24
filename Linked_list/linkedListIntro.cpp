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

void traverseLL(LinkedList* head) {
    int count = 0;
    LinkedList* temp = head;
    while(temp) {
        cout << temp->data << "  ";
        temp = temp->next;
        count++;
    }
    cout << "\nLength of LL is : " << count << "\n";
}

bool checkIfPresent(LinkedList* head, string name) {
    LinkedList* temp = head;
    while(temp) {
        if(temp->data == name)
            return true;
        temp = temp->next;

    }
    return false;
}
 


int main() {
    // int arr[] = {2, 3,4,5};
    // LinkedList* y = new LinkedList(arr[2]);
    // cout << y->next << "\n";

    // LinkedList x= LinkedList(arr[1], nullptr);
    // cout << "Value at arr[1] " << x.data << "\n";
    // cout << "Address of stored with x "<< x.next << "\n";

    vector<string> arr = {"Neha", "Vishnu", "Vishal"};
    LinkedList* head = convertArrayToLinkedList(arr);
    cout << "Convert array to LL, head = " << head->data << "\n";    

    traverseLL(head);

    cout << "\nIs my name: Jyoti present in LL? " << checkIfPresent(head, "Jyoti") << "\n";

}