#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;

    linkedlist() {
        head = NULL;
    }

    void insertatend(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
            newnode->next = head;  // circular link
            return;
        } else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;  // maintain circular link
        }
    }

    // print values in CLL and repeat head value at the end
    void printcll() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        node* temp = head;

        // print all nodes from head till last node
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        // print last node
        cout << temp->data << " ";

        // repeat head node value
        cout << head->data;
    }
};

int main() {
    linkedlist l;
    l.insertatend(20);
    l.insertatend(100);
    l.insertatend(40);
    l.insertatend(80);
    l.insertatend(60);

    l.printcll();   // output: 20 100 40 80 60 20

    return 0;
}
