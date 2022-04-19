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
