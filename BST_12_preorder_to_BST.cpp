BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    //base case, if the index exceeds of given vector size
    if(i>=preorder.size()){
        return NULL;
    }
    
    //if the element is out of range
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    //if in range
    //create new node out of the preorder vector of elements
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(preorder[i++]); //increase index after the node creation
    
    //recursive call with adjusted ranges for left and right subtrees
    root->left = solve(preorder, mini, root->data, i);
    root->right= solve(preorder, root->data, maxi, i);
    return root;

}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini= INT_MIN; //tends to - infinity
    int maxi= INT_MAX; //tends to +infinity
    int i=0;
    return solve(preorder, mini, maxi, i);
}
