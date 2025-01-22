#include<iostream>
using namespace std;

class node{
     public :
      int data;
      node* next;
     
      node(int val){
           data=val;
           next=NULL;
      }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head , int val){
    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void sort(node* &head){
    node* a , *b ;
    int temp;
    if(head==NULL){
        cout<<"empty"<<endl;
        return;
    }
    else{
        for(a=head; a->next!=NULL; a=a->next){
            for(b=a->next; b!=NULL; b=b->next){
                if(a->data > b->data){
                    temp=a->data;
                    a->data=b->data;
                    b->data=temp;
                }
            }
        }
    }
}

void display(node* head){
     node* temp = head;
    
     while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
     }
     cout<<"NULL"<<endl;
}



int main(){
    node* head = NULL;
    insertAtTail(head , 2);
    insertAtTail(head , 1);
    insertAtTail(head , 8);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
     
    display(head);
    cout<<endl;
    sort(head);
    display(head);
  
   
   return 0;
}