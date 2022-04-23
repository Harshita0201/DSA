Node* reverseDLL(Node * head)
{
    //Your code here
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *temp=curr->next;
        curr->next=prev;
        curr->prev=temp;
        prev=curr;
        curr=temp;
        
    }
    return prev;
}
