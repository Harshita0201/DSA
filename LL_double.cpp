#include<iostream>
using namespace std;
class Node{
    public: 
      int data;
      Node *next;
      Node *prev;
      
      Node(int data){ //constructor
          this->data=data;
          this->prev=NULL;
          this->next=NULL;
      }
      
      ~Node(){ //destructor
         int val= this->data;
         if(next !=NULL){
             delete next;
             next=NULL;
         }
         cout << "memory free for node with data" << val << endl;
          
      }
};

void insertAtHead(Node * &head, Node * &tail, int d){
    //if empty list 
    if(tail==NULL){
         Node *temp=new Node(d);
         head=temp;
         tail=temp;
    }else{
    
         //create node
         
         Node *temp=new Node(d);
         temp->next=head;
         head->prev=temp;
         head=temp;
    }
}

void insertAtTail(Node * &head, Node * &tail, int d){
    //if empty list 
    if(head==NULL){
         Node *temp=new Node(d);
         head=temp;
         tail=temp;
    }else{
         //create Node
         Node *temp=new Node(d);
         tail->next=temp;
         temp->prev=tail;
         tail=temp;
    }
    
}

void insertAtMiddle(Node * &head, Node * &tail, int position, int d){
    
    //if start node
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(head, tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
    
}

void deleteAtPosition(Node* &head, Node* &tail, int position){
    //if head node is to be deleted
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{ //if last or any other node in middle 
        Node *curr=head;
        Node *pre=NULL;
        
        int cnt=1;
        while(cnt<position){
            pre=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=pre;
        }
        
        curr->prev=NULL;
        pre->next=curr->next; 
        //curr->next->prev=pre;
        curr->next=NULL;
        delete curr;
        
        
    }
}

void print(Node *& head){
    Node *temp=head;
    
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

int getLength(Node *& head){
    Node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
    
int main(){
    // Node * node1= new Node(10);
    Node *head=NULL;
    Node *tail=NULL;
    
    
    // print(head);
    
    insertAtHead(head, tail, 9);
    print(head);
    
    insertAtHead(head, tail, 8);
    print(head);
    
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    insertAtTail(head, tail, 13);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    insertAtTail(head, tail, 14);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    
    insertAtMiddle(head, tail, 3, 100);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    insertAtMiddle(head, tail, 1, 101);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    insertAtMiddle(head, tail, 7, 102);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    deleteAtPosition(head, tail, 1);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    deleteAtPosition(head, tail, 3);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    
    // deleteAtPosition(head, 4);
    // print(head);
    // cout <<"Head " << head->data << endl;
    // cout <<"Tail " << tail->data << endl;
    
    deleteAtPosition(head, tail, 5);
    print(head);
    cout <<"Head " << head->data << endl;
    cout <<"Tail " << tail->data << endl;
    return 0;
}


