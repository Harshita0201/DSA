class Solution
{
    private:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int d){
        Node * cloneNode=new Node(d);
        if(cloneHead==NULL){
            cloneHead=cloneNode;
            cloneTail=cloneNode;
            return ;
        }else{
            cloneTail->next=cloneNode;
            cloneTail=cloneNode;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        
        //step 1. clone linked list with next pointer 
        Node *temp=head;
        Node *cloneHead=NULL;
        Node *cloneTail=NULL;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp=temp->next;
        }
        
        //step 2. create map, store mapping of original node to clone nodes
        unordered_map<Node*, Node*> mapping;
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL){
            mapping[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        
        //3. cpoy the random pointers in clone linked list
        originalNode=head;
        cloneNode=cloneHead;
        
        while(originalNode!=NULL){
            cloneNode->arb=mapping[originalNode->arb];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
        
    }

};
