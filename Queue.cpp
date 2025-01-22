#include<iostream>
using namespace std;

class Queue{
    private:

    int* arr;
    int front;
    int rear;
    int maxsize;

    public:

    Queue(int size=5){
        maxsize=size;
        arr = new int[maxsize];
        front=-1;
        rear=-1;
    }
    ~Queue(){
        delete[] arr;
    }

    bool full(){
        return rear==maxsize-1;
    }

    bool empty(){
        return rear==-1 && front==-1;
    }

    bool enQueue(int x){
        if(full()){
            cout<<"Queue is full "<<endl;
            return false;
        }
        
        else if(empty()){
            arr[++rear]=x;
            ++front;
            return true;
        }

        else{
            arr[++rear]=x;
            return true;
        }
    }

    bool deQueue(){
        if(empty()){
            cout<<" Queue is empty "<<endl;
            return false;
        }
        else if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
        ++front;
        }
        return true;
    }

    int frontvalue(){
        if(empty()){
            cout<<" Queue is empty "<<endl;
            return 0;
        }
        return arr[front];
    }

    void show(){
        if(empty()){
            cout<<" Queue is empty "<<endl;
            return ;
        }

        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" "<<endl;
        }
    }
    
};

int main(){
    Queue q(3);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    cout<<" Front value "<<q.frontvalue()<<endl;
    q.deQueue();
    q.show();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    return 0;
}