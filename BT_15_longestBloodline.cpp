void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
        //base case if leaf node
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }
            else if(len==maxLen){
                maxSum=max(sum, maxSum);
            }
            return;
        }
        
        //update sum if not leaf node
        sum=sum+root->data;
        
        //recursive left and right calls & increase len for next level
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxLen=0;
        
        int sum=0;
        int maxSum=INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
        
    }
