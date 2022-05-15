//Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node* root){
        //base case
        if(root==NULL){
            pair<int, int> p =make_pair(0,0);
            return p;
        }
        
        //recursive calls for left and right BT
        pair<int, int> left=solve(root->left);
        pair<int, int> right=solve(root->right);
        
        pair<int, int> res;
        
        res.first= root->data + left.second + right.second; //inclusing current level node data and data from nodes of level next to next
        res.second=max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans= solve(root);
        return max(ans.first, ans.second);
        
    }
};
