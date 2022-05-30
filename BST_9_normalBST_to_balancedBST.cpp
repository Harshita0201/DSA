void inorder(TreeNode<int>* root, vector<int> &in){
    //base case
    if(root==NULL){
        return;
    }
    //L
    inorder(root->left, in);
    //N
    in.push_back(root->data);
    //R
    inorder(root->right, in);
}
TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    //base case
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    //create a root node from the middle value of the vector of inorder of bst
    TreeNode<int>* root= new TreeNode<int>(in[mid]);
    //recursive calls for left and right subtrees
    root->left= inorderToBST(s, mid-1, in);
    root->right= inorderToBST(mid+1, e, in );
    
    return root;
    
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorderVal;
    //store the inorder traversal of bst into the vector-inorderVal
    inorder(root, inorderVal);
    
    return inorderToBST(0, inorderVal.size()-1, inorderVal);
}
