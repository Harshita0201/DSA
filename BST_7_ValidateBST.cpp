bool isBST(BinaryTreeNode<int> *root, int min, int max){
    //base case 
    if(root==NULL){
        return true;
    }
    //check for root node
    if(root->data >= min  && root->data<= max){
        //recursive check for left and right subtrees
        bool left=isBST(root->left, min, root->data);
        bool right=isBST(root->right, root->data, max);
        return left && right;
    }else{
        return false;
    }
    
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root, INT_MIN, INT_MAX); //range for root node is from -infi to + infi
}
