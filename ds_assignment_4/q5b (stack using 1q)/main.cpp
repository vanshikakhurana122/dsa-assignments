#include <iostream>
using namespace std;
#define MAX 20

class Queue{
    private:
    int element[MAX];
    int rear;
    int front;
    
    public:
    Queue(){
        rear=front=-1;
    }
    
    bool isEmpty(){
        if (front>rear || front==-1) return true;
        else return false;
    }
    
    bool isFull(){
        if (rear==MAX-1) return true;
        else return false;
    }
    
    void enqueue(int x){
        if(isFull()) cout<<"overflow"<<endl;
        else if(front==-1 && rear==-1){
            rear=front=0;
            element[rear]=x;
        }
        else{
            rear++;
            element[rear]=x;
        }
    }
    
    int dequeue(){
        if(isEmpty()) return -1;
        else if(front==0 && rear==0){
            int item=element[front];
            front=rear=-1;
            return item;
        }
        else{
            int item=element[front];
            front++;
            return item;
        }
    }
    
    char peek(){
        if(isEmpty()) return -1;
        else return element[front];
    }
    
    int size(){
        return rear-front+1;
    }
    
    void display(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else{
            cout<<"queue items: ";
            for(int i=front; i<=rear; i++){
                cout<<element[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"enter number of elements: ";
    cin>>n;
    Queue q;
    
    for(int i=0; i<n; i++){
        int val;
        cout<<"enter value to enqueue: ";
        cin>>val;
        
        q.enqueue(val);
        
        for(int j=0; j<i; j++){
            q.enqueue(q.dequeue());
        }
    }
    
    q.display();

    return 0;
}