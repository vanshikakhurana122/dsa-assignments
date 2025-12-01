#include <iostream>
using namespace std;
#define MAX 20

class Queue{
    private:
    char element[MAX];
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
    
    void enqueue(char x){
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
    
    void dequeue(){
        if(isEmpty()) return;
        else if(front==0 && rear==0){
            int item=element[front];
            front=rear=-1;
        }
        else{
            int item=element[front];
            front++;
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
    string str;
    cout<<"enter string (lowercase only): ";
    getline(cin, str);
    
    int count[26]={0};
    Queue q;
    int n=str.length();
    
    for(int i=0; i<n; i++){
        char ch=str[i];
        int index=ch-'a';
        count[index]++;
        q.enqueue(ch);
        
        while (!q.isEmpty() && count[q.peek()-'a']>1){
            q.dequeue();
        }
        
        if(q.isEmpty()) cout<<"-1";
        else cout<<q.peek();
    }

    return 0;
}