pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    //find the key 
    BinaryTreeNode<int>* temp= root;
    int pred=-1;
    int succ=-1;
    
    while(temp->data!=key){
        if(temp->data>key){//key small, goto L
            //before goind save temp->data as it can be possible succ as it is greater that key
            succ= temp->data;
            temp=temp->left;
        }else{//key is greater, goto R
            //before going save temp->data, as it can be possible pred as it is smaller
            pred=temp->data;
            temp=temp->right;
        }
    }
    
    //find pred and succ
    //pred-> max element in left subtree---rightmost child in left subtree
    BinaryTreeNode<int>* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right; //got to extreme right to fetch max element
    }
    
    //succ-> min element in rightt subtree---lefttmost child in right subtree
    BinaryTreeNode<int>* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left; //got to extreme right to fetch max element
    }
    
    pair<int, int> ans= make_pair(pred, succ);
    return ans;
    
    
}
