//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

/*  Function which returns the  root of 
    the flattened linked list. */
// Node *merge(Node *a, Node * b){
//     if(a==NULL){
//         return b;
//     }
//     if(b==NULL){
//         return a;
//     }
    
//     Node *result;
    
//     if(a->data < b->data){
//         result=a;
//         result->bottom=merge(result->bottom, b); //add linked list to bottom of result
        
//     }else{
//         result=b;
//         result->bottom=merge(a, b->bottom);
//     }
    
//     result->next=NULL; //mark end
//     return result;
// }    

Node *merge(Node *a, Node *b){
    Node *temp= new Node(0);
    Node *res=temp;
    
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    
    if(a){//if a is left
        temp->bottom=a;
    }else{
        temp->bottom=b;
    }
    return res->bottom;
    
}//TC: O(N) SC:O(1)

Node *flatten(Node *root)
{
   //base case    
   if(root==NULL || root->next==NULL){
       return root;
   }
   
   //recur the list on root->next or right
   root->next=flatten(root->next);
   
   //merge root and root->next
   root= merge(root, root->next);
   
   return root;
}//TC: O(N) 
