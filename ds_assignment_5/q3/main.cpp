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
    
    void findMiddle(){
        if(head==NULL){
            cout<<"empty list"<<endl;
            return;
        }
        
        int count=0; //number of nodes
        Node* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        if(count%2==0){
            cout<<"even nodes - no middle node"<<endl;
            return;
        }
        
        int mid=count/2;
        temp=head;
        for(int i=1; i<=mid; i++){
            temp=temp->next;
        }
        cout<<"middle node: "<<temp->data<<endl;
        
    }
    
    
};

int main()
{
    LinkedList list, list2;
    
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    list.insertEnd(7);
    list.insertEnd(8);
    list.insertEnd(9);
    list.findMiddle();
    
    list2.insertEnd(1);
    list2.insertEnd(2);
    list2.insertEnd(3);
    list2.insertEnd(4);
    list2.findMiddle();

    return 0;
}