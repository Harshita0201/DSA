Node * solve(Node *root, int &k, int node){
    //base case 
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){ //if node n is found
        return root;
    }
    
    //left and right recursive calls
    Node* leftAns=solve(root->left, k, node);
    Node* rightAns=solve(root->right, k, node);
    
    //case 1
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX; //to lock ans i.e current root node
            return root;
        }
        return leftAns;
    }
    
    //case 2
    if(rightAns!=NULL && leftAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX; //to lock ans i.e current root node
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans=solve(root, k, node);
    
    if(ans==NULL || ans->data==node){
        return -1;
    }else{
     return ans->data;   
    }
}
