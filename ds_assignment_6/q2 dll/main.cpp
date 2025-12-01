#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert after a specific value
    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Insert before a specific value
    void insertBefore(int key, int val) {
        if (head == NULL) return;

        // If key at head
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }

        Node *temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    // Delete a node by value
    void deleteNode(int key) {
        if (head == NULL) return;

        Node *temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        // If deleting head
        if (temp->prev == NULL) {
            head = temp->next;
            if (head != NULL) head->prev = NULL;
        }
        // Middle or last node
        else {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Search
    void search(int key) {
        Node *temp = head;
        int pos = 1;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
            pos++;
        }

        if (temp == NULL)
            cout << "Node " << key << " not found.\n";
        else
            cout << "Node " << key << " found at position " << pos << ".\n";
    }

    // Display list
    void display() {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int ch, val, key;

    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search\n7. Display\n8. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cin >> val;
            dll.insertAtBeginning(val);
            break;
        case 2:
            cin >> val;
            dll.insertAtEnd(val);
            break;
        case 3:
            cin >> key >> val;
            dll.insertAfter(key, val);
            break;
        case 4:
            cin >> key >> val;
            dll.insertBefore(key, val);
            break;
        case 5:
            cin >> key;
            dll.deleteNode(key);
            break;
        case 6:
            cin >> key;
            dll.search(key);
            break;
        case 7:
            dll.display();
            break;
        case 8:
            break;
        default:
            cout << "Invalid\n";
        }

    } while (ch != 8);

    return 0;
}