#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int d){ //constructor
        this->data=d;
        this->next=NULL;
    }
    
    ~Node(){//destructor
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout <<"The deleted node data is " << val << endl;
    }
    
};

void insertNode(Node* &tail, int element, int d){
    
    
    //empty list
    if(tail==NULL){
        Node* newNode= new Node(d); //create the node
        tail=newNode; //point tail to newNode
        newNode->next=tail; //point newNode's next to itself
    }else{//non empty list
        //assuming the element is already in the list 
        Node *curr=tail;
        
        while(curr->data!=element){
            curr=curr->next;
        }
        
        //element found->curr @element Node
        //create new Node
        Node* temp= new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
    
}

void deleteNode(Node * &tail, int ele){
    //if list is empty
    if(tail==NULL){
        cout << "list is empty, try again" << endl;
    }else{
        //non empty list
        //we assume element is present 
        
        Node *prev=tail;
        Node *curr=prev->next;
        //traverse till element is found
        while(curr->data!=ele){
            prev=curr;
            curr=curr->next;
        }
        //element found at curr
        
        prev->next=curr->next;
        
        //if only 1 node to be deleted
        if(curr==prev){
            tail=NULL;
        }
        //if tail node is to be deleted
        else if(tail==curr){
            tail=prev;
        }
        
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &tail){
    Node *temp=tail;
    
    if(tail==NULL){
        cout << "List is empty" << endl;
        return;
    }
    do{
        cout << tail->data << " ";
        tail=tail->next;
    }while(tail!=temp); //tail is not equal to itself i.e temp
    cout << endl;
}


int main(){
    Node *tail=NULL;
    
    insertNode(tail, 5, 3); 
    print(tail);
    
    insertNode(tail, 3, 5); 
    print(tail);
    
    insertNode(tail, 5, 7); 
    print(tail);
    
    insertNode(tail, 5, 6); 
    print(tail);
    
    insertNode(tail, 3, 4); 
    print(tail);
    
    deleteNode(tail, 3);
    print(tail);
    
    deleteNode(tail, 5);
    print(tail);
    return 0;
}
