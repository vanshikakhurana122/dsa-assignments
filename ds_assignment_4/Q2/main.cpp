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
        if (front==-1) return true;
        else return false;
    }
    
    bool isFull(){
        if ((rear+1)%MAX==front) return true; //rear+1 is front basically
        else return false;
    }
    
    void enqueue(int x){
        if(isFull()) cout<<"overflow"<<endl;
        else if(front==-1){ //first element
            rear=front=0;
            element[rear]=x;
            cout<<x<<" enqueued";
        }
        else{
            rear=(rear+1)%MAX;
            element[rear]=x;
            cout<<x<<" enqueued";
        }
    }
    
    void dequeue(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else if(front==rear){
            int item=element[front];
            cout<<"item deleted: "<<item<<endl;
            front=rear=-1;
        }
        else{
            int item=element[front];
            cout<<"item deleted: "<<item<<endl;
            front=(front+1)%MAX;
        }
    }
    
    void peek(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else cout<<"front element: "<<element[front]<<endl;
    }
    
    void display(){
        if(isEmpty()) cout<<"queue is empty"<<endl;
        else{
            cout<<"queue items: ";
            int i=front;
            while(true){
                cout<<element[i]<<" ";
                if (i==rear) break;
                i=(i+1)%MAX;
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