TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    //base case
    if(root==NULL){
        return NULL;
    }
    //iterative soln:
    while(root!=NULL){
         if(root->data < P->data && root->data < Q->data) //P,Q larger lies in right subtree, goto R
             root=root->right;
         else if(root->data > P->data && root->data > Q->data) //P,Q smaller lies in leftt subtree, goto L
             root=root->left;
         else
             return root;
    }
    //recursive soln:
//     if(root->data < P->data && root->data < Q->data){ //P,Q larger lies in right subtree, goto R
//         return LCAinaBST(root->right, P, Q);
//     }
//     if(root->data > P->data && root->data > Q->data){ //P,Q smaller lies in leftt subtree, goto L
//         return LCAinaBST(root->left, P, Q);
//     }
//     return root;
}
