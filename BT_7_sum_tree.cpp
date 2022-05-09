 pair<bool, int> isSumTree_fast(Node *root){
        // Your code here
         //base case
         if(root==NULL){
             pair<bool, int> p=make_pair(true, 0);
             return p;
         }
         
         
         //if leaf nodes
         if(root->left==NULL && root->right==NULL){
             pair<bool, int> p=make_pair(true, root->data);
             return p;
         }
         
         //recurisve calls for left and right subtrees
         pair<bool,int> isSumLeft=isSumTree_fast(root->left);
         pair<bool,int> isSumRight=isSumTree_fast(root->right);
         
         //check bool condition for both the left and right subtress
         bool leftAns=isSumLeft.first;
         bool rightAns=isSumRight.first;
         
         //check if root->data=L+R
         bool cond = root->data == isSumLeft.second + isSumRight.second;
         
         
         pair<bool, int> ans;
         if(leftAns && rightAns && cond){
             ans.first=true;
             ans.second=root->data + isSumLeft.second + isSumRight.second;
         }else{
             ans.first=false;
         }
         return ans;
         
         
    }
    bool isSumTree(Node* root)
    {
         
         return isSumTree_fast(root).first;
         
    }
