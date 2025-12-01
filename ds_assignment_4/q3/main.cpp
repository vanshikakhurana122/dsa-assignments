#include <iostream>
using namespace std;
#define MAX 100

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
    
    int peek(){
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

void interleave(Queue q){
    int n=q.size();
    if(n%2!=0){
        cout<<"interleaving not possible"<<endl;
        return;
    }
    int half=n/2;
    Queue q1;
    Queue q2;
    
    //dequeue first half of q and enqueue in q1
    for(int i=0; i<half; i++){
        q1.enqueue(q.dequeue());
    }
    
    //interleave elements in q3 (first q1 then q)
    while(!q1.isEmpty()){
        q2.enqueue(q1.dequeue());
        q2.enqueue(q.dequeue());
    }
    cout<<"interleaved queue: "<<endl;
    q2.display();
}

int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);
    
    q.display();
    
    interleave(q);

    return 0;
}