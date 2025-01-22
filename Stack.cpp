#include<iostream>
using namespace std;

class Stack{
    private:
     int arr[100];
     int maxsize;
     int top;

     public:
      Stack(int size=100){
          maxsize=size;
          top=-1;
      }

      bool full(){
           return top==maxsize-1;
      }   
      
      bool empty(){
           return top==-1;
      }

      bool push(int x){
        if(full()){
           cout<<" Stack is full "<<endl;
           return false;
        }
        arr[++top]=x;
        return true;
      }

      bool pop(){
        if(empty()){
            cout<<" Stack is empty "<<endl;
            return false;
        }
        top--;
        return true;
      }

      int topelement(){
        if(empty()){
            cout<<" Stack is empty "<<endl;
            return 0;
        }
        return arr[top];
      }
      
      void show(){
        if(empty()){
            cout<<" Stack is empty " <<endl;
            return; 
        }
        for(int i=top; i>=0; i--){
            cout<<arr[i]<<" "<<endl;
        }
      }

};

int main(){
      Stack s;
      s.push(1);
      s.push(2);
      s.push(3);
      s.push(4);
      s.push(5);
      s.push(6);
      s.push(7);
      s.push(8);
      cout<<"Top element "<<s.topelement()<<endl;
      s.pop();
      s.show();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
      s.pop();
  
  return 0;
};