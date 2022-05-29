int solve(BinaryTreeNode<int>* root, int &i,  int k){
    if(root==NULL){
        return -1;
    }
    //Left
    int left = solve(root->left, i, k);
    
    if(left!=-1){
        return left; 
    }
    //NODE
    i++; //increment value of i while returning from left subtree
    if(i==k){
        return root->data;
    }
    
    //RIGHT
    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root, i, k);
    return ans;
}
