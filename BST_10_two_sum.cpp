void inorder(BinaryTreeNode<int>* root, vector<int> &in){
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

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    
    vector<int> inorderVal;
    //store the inorder traversal of BST, as it is in sorted order
    inorder(root, inorderVal);
    
    //use 2 pointer approach to check if pair exists that gives sum equal to target
    int i=0;
    int j=inorderVal.size()-1;
    while(i<j){
        if(inorderVal[i]+inorderVal[j]==target){
            return true;
        }else if(inorderVal[i]+inorderVal[j]>target){//sum greater than target
            j--;
        }else{//sum smaller than target
            i++;
        }
    }
    return false; //proccessed whole vector, pair still not found
}
