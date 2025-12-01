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
    
    int deleteEnd(){
        if(head==NULL) return -1;
        Node* temp=head;
        Node* prev=NULL;
        
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        
        if(temp==head) head=NULL; //one element in list
        else prev->next=NULL;
        
        return temp->data;
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
    
    int count(){
        if(head==NULL) return -1;
        Node* temp=head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }
};

int main()
{
    LinkedList list1, list2;
    
    list1.insertEnd(1);
    list1.insertEnd(2);
    list1.insertEnd(3);
    list1.insertEnd(4);
    cout<<"original list: ";
    list1.display();
    cout<<endl;
    
    int n=list1.count();
    
    for(int i=1; i<=n; i++){
        list2.insertEnd(list1.deleteEnd());
    }
    cout<<"reversed list: ";
    list2.display();
    cout<<endl;
    

    return 0;
}