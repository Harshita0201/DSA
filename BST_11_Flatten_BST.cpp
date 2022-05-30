void inorder(TreeNode<int>* root, vector<int> &in){
    //base case
    if(root==NULL){
        return;
    }
    //inorder -> LNR
    //Left
    inorder(root->left,in);
    //Node
    in.push_back(root->data);
    //Right
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    
    vector<int> inorderVal;
    //store the inorder traversal of BST, as it is in sorted order
    inorder(root, inorderVal);
    int n= inorderVal.size();
    //create node of the first value from the vector of inorder traversal
    TreeNode<int>* newRoot= new TreeNode<int>(inorderVal[0]);
    
    TreeNode<int>* curr= newRoot; //initially current pointer at newRoot
    
    //2nd step flatten
    for(int i=1; i<n; i++){ //strat from 2nd val of vector
        TreeNode<int>* temp= new TreeNode<int>(inorderVal[i]);
        
        curr->left=NULL;
        curr->right= temp;
        curr=temp; //moce curr ahead
        
    }
    
    //3rd Step for last node
    curr->left= NULL;
    curr->right= NULL;
    
    return newRoot;
    
}
