#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
Node* floydDetectLoop(Node *head){
    Node *slow=head;
    Node *fast=head;
    
    if(head==NULL){
        return NULL;
    }
    
    while(slow!=NULL && fast!=NULL){
         fast=fast->next;
         if(fast->next!=NULL){
             fast=fast->next;
         }
         slow=slow->next;
         if(slow==fast){
             return slow;
         }
         
    }
    
    return NULL;

    
}

Node * detectStartOfLoop(Node *head){
    if(head==NULL){
        return NULL;
    }
    
    Node *intersection=floydDetectLoop(head);
    Node *slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}


int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectStartOfLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
    return 0;
}
