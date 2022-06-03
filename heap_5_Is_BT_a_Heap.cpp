int countNodes(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int cnt= 1 + countNodes(root->left) + countNodes(root->right);
        
        return cnt;
    }
    
    bool isCBT(struct Node *root, int i, int totalCount){
        //base case
        if(root==NULL){
            return true;
        }
        
        //if index of current node is out of bounds
        if(i>=totalCount){
            return false;
        }else{ //index of current node within bounds
            //check for left and right child
            
            bool left= isCBT(root->left, 2*i+1,totalCount);
            bool right=isCBT(root->right, 2*i+2, totalCount);
            
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node *root){
        //if leaf node
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        //if left child only
        if(root->right==NULL){
            return (root->data > root->left->data);
        }else{ //has left and right child both
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            
            return ( (left && right) && (root->left->data < root->data) && (root->right->data < root->data));
              
        }
        
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int totalCount=countNodes(tree);
        
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)){
            return true;
        }else{
            return false;
        }
    }
