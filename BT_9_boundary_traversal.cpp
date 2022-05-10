void traverseLeft(Node *root, vector<int> &ans){
        //if no node and leaf nodes
        if( (root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        //print or store current node
        ans.push_back(root->data);
        
        //traverse rest of the left part of BT
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node *root, vector<int> &ans){
        //base case of no node
        if(root==NULL){
            return;
        }
        
        //if leaf nodes
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        //traverse rest of the leaf nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node *root, vector<int> &ans){
        //base case if no node or leaf node
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        //traverse till right untill leaf node
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        
        //while returning print or store the ans
        ans.push_back(root->data);
        
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        //print/ store root
        ans.push_back(root->data);
        
        
        //traverse left
        traverseLeft(root->left, ans);
        
        
        //traverse leaf nodes
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        
        //traverse right
        traverseRight(root->right, ans);
        
        return ans;
        
    }
