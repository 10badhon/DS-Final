#include<iostream>
using namespace std;

class Queue{
    private :
    int* arr;
    int front;
    int rear;
    int maxsize;

    public:
     Queue(int size=4){
         maxsize=size;
         arr = new int[maxsize];
         front=-1;
         rear=-1;
     }
     ~Queue(){
        delete[] arr;
     }

     bool empty(){
        return front==-1 && rear==-1;
     }
     bool full(){
        return (rear+1)%maxsize==front;
     }
     bool enqueue(int x){
        if(full()){
            cout<<"Queue is full"<<endl;
            return false;
        }
        else if(empty()){
           front=0;
           rear=0;
           arr[rear]=x;
           return true;
        }
        else{
            rear=(rear+1)%maxsize;
            arr[rear]=x;
             return true;
        }
     };
     bool dequeue(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return false;
        }
        else if(front==rear){
            front=-1;
            rear=-1;
            return true;
        }
        else{

            front=(front+1)%maxsize;
            return true;
        }
     }
     int frontvalue(){
        if(empty()){
          cout<<"Queue is empty"<<endl;
          return 0;
        }
        return arr[front];
     }

     void show(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        if(front<rear){
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<endl;
            }
        }
        else{
            for(int i=front; i<maxsize; i++){
                cout<<arr[i]<<endl;
            }
            for(int i=0; i<=rear; i++){
                cout<<arr[i]<<endl;
            }
        }
        
     }

};


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.dequeue();
    q.dequeue();

    q.enqueue(5);
    q.enqueue(6);

    q.enqueue(7);

    cout<<"Front value"<<q.frontvalue()<<endl;

    q.show();

    return 0;
}
