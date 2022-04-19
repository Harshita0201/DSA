#include<iostream>
using namespace std;
class Node{
    public:
       int data;
       Node* next;
       
       Node(int data){ //constructor
           this->data=data;
       }
       
       ~Node(){ //destructor
           int value=this->data;
           if(this->next!=NULL){
               delete next;
               this->next=NULL;
           }
       }
};


void InsertAtBeginning(Node* &head, int d){
    //create new Node
    Node * temp= new Node(d);
    temp->next=head; //store add of previously head node/start node
    head=temp; //point head to new inserted node
}

void InsertAtTail(Node* &tail, int d){
    //create new Node
    Node *temp = new Node(d);
    tail->next=temp; //add next node to previously tail node
    tail=temp; //new tail is new node
}

void deleteNode(Node* &head, Node* &tail, int position){
    //if start Node
    if(position==1){
        Node *temp=head; //temp is the node to be deleted i.e first node, therefore point it to head
        head=head->next; //ppoint head to next node
        //free memory
        temp->next=NULL; //break the link, mark next as null
        delete temp;// finally delete
    }else{ //delete at any position/ middle
        
        int cnt=1;
        Node *curr=head;
        Node *prev=NULL;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){ //last node to delete
            tail=prev; //handle tail
        }
        
        prev->next=curr->next; // readjust links
        curr->next=NULL; // break link mark next as null
        delete curr; //delete
        
    }
}

void InsertAtMiddle(Node* &head, Node* &tail, int position, int d){
    //if start
    if(position==1){
        InsertAtBeginning(head, d);
    }
    
    Node *temp =head;
    int cnt=1;
    
    //if end
    if(temp->next==NULL){
        InsertAtTail(tail, d);
        return; 
    }
    
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    //creating the new Node
    Node *nodeToInsert = new Node(d);
    
    nodeToInsert->next= temp->next;
    temp->next = nodeToInsert;
}

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next; //move ahead
    }
    cout << endl;
}

int main(){
    Node * node1 = new Node(10);
    
    cout << node1->data << endl;
    cout << node1->next << endl;
    
    Node * head= node1;
    Node * tail= node1;
    cout << endl;
    
    // InsertAtBeginning(head, 12);
    
    // print(head);
    
    // InsertAtBeginning(head, 15);
    // InsertAtBeginning(head, 16);
    
    // print(head);
    
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 14);
    
    
    InsertAtMiddle(head, tail, 5, 15);
    InsertAtMiddle(head, tail, 6, 90);
    InsertAtMiddle(head, tail, 1, 85);
    
    print(head);
    
    deleteNode(head,tail, 1);
    print(head);
    cout << "Head " << head->data <<endl;
    cout << "Tail " << tail->data << endl;
    
    deleteNode(head,tail, 7);
    print(head);
    cout << "Head " << head->data <<endl;
    cout << "Tail " << tail->data << endl;
    
    deleteNode(head,tail, 3);
    print(head);
    
    cout << "Head " << head->data <<endl;
    cout << "Tail " << tail->data << endl;
    return 0;
}
