void inorder(TreeNode<int> *root, vector<int>& in){
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

vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2){ //merge sort
    vector<int> ans(bst1.size()+bst2.size());
    
    int i=0, j=0, k=0;
    
    while(i<bst1.size() && j < bst2.size()){
        if(bst1[i]< bst2[j]){
            ans[k++]=bst1[i];
            i++;
        }else{
            ans[k++]=bst2[j];
            j++;
        }
    }
    
    while(i<bst1.size()){
        ans[k++]=bst1[i];
        i++;
    }
    
    while(j<bst2.size()){
        ans[k++]=bst2[j];
        j++;
    }
    return ans;
}
TreeNode<int> * inorderToBST(int s, int e, vector<int> &merged){
    //base case
    if(s>e){
        return NULL;
    }
    
    int mid=(s+e)/2;
    TreeNode<int> * root= new TreeNode<int>(merged[mid]);
    root->left=inorderToBST(s, mid-1, merged);
    root->right=inorderToBST(mid+1, e, merged);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    //step 1 store the inorder of both the BSTs
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    //step 2:now we have got two vectors/ arrays with sorted values- merge them to get one sorted vector
    vector<int> merged= mergeArrays(bst1, bst2);
    
    //step 3: convert the sorted (inorder) into bst
    int s=0;
    int e=merged.size()-1;
    return inorderToBST(s, e, merged);
    
}
