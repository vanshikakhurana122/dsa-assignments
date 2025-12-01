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
    
    void insertBeg(int data){
        Node* newNode = new Node();
        newNode->data=data;
        newNode->next=head;
        head=newNode;
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
    
    void insertAfterValue(int existingValue, int newValue){
        Node* newNode = new Node(newValue);
        Node* temp=head;
        
        //empty ll
        if(head==NULL){
            head=newNode;
            return;
        }
        
        //else traverse to value 
        while(temp!=NULL && temp->data!=existingValue){ //either ll ends or value is found
            temp=temp->next;
        }
        if(temp==NULL) cout<<"value not found"<<endl;
        else{
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    
    void insertPos(int pos, int value){
        Node* newNode = new Node(value);
        Node* temp=head;
        
        if(pos<0) {
            cout<<"invalid position"<<endl;
            return;
        }
        if(pos==1){
            newNode->next=temp;
            head=newNode;
            return;
        }
        for(int i=1; i<pos-1; i++){
            temp=temp->next;
            if(temp==NULL){
                cout<<"invalid position"<<endl;
                return;
            }
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
    }
    
    void deleteBeg(){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=temp->next;
        cout<<temp->data<<" deleted"<<endl;
        delete temp;
    }
    
    void deleteEnd(){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        Node* prev=NULL;
        
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        
        if(temp==head) head=NULL; //one element in list
        else prev->next=NULL;
        
        cout<<temp->data<<" deleted"<<endl;
        delete temp;
    }
    
    void deleteValue(int val){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        Node* prev=NULL;
        
        //traverse to value
        while(temp!=NULL && temp->data!=val) {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"element not found"<<endl;
            return;
        }
        
        if(temp==head) head=head->next;
        else if (temp->next==NULL) prev->next=NULL;
        else prev->next=temp->next;
        
        cout<<temp->data<<" deleted"<<endl;
        delete temp;
    }
    
    void deletePos(int pos){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        Node* prev=NULL;
        
        if(pos<0) {
            cout<<"invalid position"<<endl;
            return;
        }
        
        if(pos==1){
            head=head->next;
            delete temp;
            return;
        }
        
        for(int i=1; i<pos; i++){
            prev=temp;
            temp=temp->next;
            if (temp==NULL){
                cout<<"invalid position"<<endl;
                return;
            }
        }
        
        if(temp==head) head=head->next;
        else if (temp->next==NULL) prev->next=NULL;
        else prev->next=temp->next;
        
        cout<<temp->data<<" deleted from position "<<pos<<endl;
        delete temp;
    }
    
    void search(int x){
        if(head==NULL) {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        int count=1;
        while(temp!=NULL && temp->data!=x){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            cout<<"element not found"<<endl;
            return;
        }
        cout<<"element found at position: "<<count<<endl;
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
};

int main()
{
    LinkedList list;
    int choice, value, pos;
    
    do{
        cout<<endl<<"LINKED LIST OPERATIONS: "<<endl;
        cout<<"1. insert at beginning"<<endl;
        cout<<"2. insert at end"<<endl;
        cout<<"3. insert after value"<<endl;
        cout<<"4. insert at position"<<endl;
        cout<<"5. deletion from beginning"<<endl;
        cout<<"6. deletion from end"<<endl;
        cout<<"7. delete value"<<endl;
        cout<<"8. delete position"<<endl;
        cout<<"9. search node"<<endl;
        cout<<"10. display list"<<endl;
        cout<<"11. exit"<<endl;
        cin>>choice;
        
        switch (choice){
            case 1:
                cout<<"enter value to insert: ";
                cin>>value;
                list.insertBeg(value);
                break;
            case 2:
                cout<<"enter value to insert: ";
                cin>>value;
                list.insertEnd(value);
                break;
            case 3:
                int existing;
                cout<<"enter existing value: ";
                cin>>existing;
                cout<<"enter value to insert: ";
                cin>>value;
                list.insertAfterValue(existing,value);
                break;
            case 4:
                cout<<"enter position: ";
                cin>>pos;
                cout<<"enter value to insert: ";
                cin>>value;
                list.insertPos(pos,value);
                break;
            case 5:
                list.deleteBeg();
                break;
            case 6:
                list.deleteEnd();
                break;
            case 7:
                cout<<"enter value to delete: ";
                cin>>value;
                list.deleteValue(value);
                break;
            case 8:
                cout<<"enter position to delete: ";
                cin>>pos;
                list.deletePos(pos);
                break;
            case 9:
                cout<<"enter value to find: ";
                cin>>value;
                list.search(value);
                break;
            case 10:
                list.display();
                break;
            case 11:
                cout<<"exiting program.";
                break;
            default:
                cout<<"invalid choice.";
                break;
        }
    } while (choice!=11);
    

    return 0;
}