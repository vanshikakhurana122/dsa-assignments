#include <iostream>
using namespace std;
#define MAX 5

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
    
    void dequeue(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else if(front==0 && rear==0){
            int item=element[front];
            cout<<"item deleted: "<<item<<endl;
            front=rear=-1;
        }
        else{
            int item=element[front];
            cout<<"item deleted: "<<item<<endl;
            front++;
        }
    }
    
    void peek(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else cout<<element[front];
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
    Queue s;
    int choice, value;
    
    do{
        cout<<endl<<"QUEUE OPERATIONS MENU:"<<endl;
        cout<<"1. enqueue"<<endl;
        cout<<"2. dequeue"<<endl;
        cout<<"3. peek front element"<<endl;
        cout<<"4. display queue"<<endl;
        cout<<"5. check if empty"<<endl;
        cout<<"6. check if full"<<endl;
        cout<<"7. exit"<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>choice;
        
        switch (choice){
            case 1:
                cout<<"enter value to enqueue: ";
                cin>>value;
                s.enqueue(value);
                break;
            case 2:
                s.dequeue();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                if (s.isEmpty()) cout<<"queue is empty.";
                else cout<<"queue is not empty.";
                break;
            case 6:
                if (s.isFull()) cout<<"queue is full.";
                else cout<<"queue is not full.";
                break;
            case 7:
                cout<<"exiting program.";
                break;
            default:
                cout<<"invalid choice.";
                break;
        }
    } while (choice!=7);

    return 0;
}