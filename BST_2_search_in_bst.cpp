bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *temp = root; // set temp pointer at root
    
    
    while(temp!=NULL){
        
        if(temp->data ==x){ //match found
            return true; 
        }
        
        if(temp->data > x){ //x is small goto left
            temp=temp->left;
        }
        else{ //x is greater, goto right 
            temp=temp->right;
        }
    }
    return false; // no match found
    
}
