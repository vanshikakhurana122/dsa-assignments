#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList{
    private:
    Node* head;
    
    public:
    LinkedList(){
        head=NULL;
    }
    
    void insertEnd(int data){
        Node* newNode = new Node(data);
        //if ll was empty, assign to head
        if(head==NULL){
            head=newNode;
            return;
        }
        
        //else traverse till end of ll
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next; //keep moving forward till last node
        }
        
        //insert after last
        temp->next=newNode; //temp->newNode->NULL
    }
    
    void display(){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    void deleteValue(int val){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        
        int count=0;
        
        while(head!=NULL && head->data==val){
            Node* toDelete=head;
            head=head->next;
            delete toDelete;
            count++;
        }
        
        Node* temp=head;
        Node* prev=NULL;
        
        while(temp!=NULL){
            if(temp->data==val){
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
                count++;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        
        cout<<"count: "<<count<<endl;
        display();
    }
    
    
};

int main()
{
    LinkedList list;
    
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(1);
    
    list.deleteValue(1);


    return 0;
}