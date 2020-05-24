#include <iostream>
#include <conio.h>

struct Node{
    int data[3];
    Node *next;
};

class Stack{
    Node *top;
    public:
    static int size;
    Stack(){
        top = NULL;
        // size = 0;
    }
    void push(int n[]);
    int * pop();
    // show(void);
    ~Stack();
};

int Stack::size =0;

void Stack::push(int n[]){
    Node *temp = new Node;
    // temp->data = n;
    std::copy(n,n+3,temp->data);
    temp->next = top;
    top = temp;
    Stack::size++;
}

int * Stack::pop(){
    static int dt[3];
    if(top!=NULL){
        Node *temp = top;
        top = top->next;
        // dt = temp->data;
        std::copy(temp->data,temp->data+3,dt);
        Stack::size--;
        return dt;
        // delete temp;
    }
}

// void Stack::show(){
//     Node *temp = top;
//     while(temp!=NULL){

//     }
// }

Stack::~Stack(){
    while(top!=NULL){
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

