void solve(Node *root, vector<int> &ans, int level){
    if(root==NULL){
        return;
    }
    
    //for reaching new level
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    //recursive calls for next levels right to left
    
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
    
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your code here
        vector<int> ans;
        solve(root, ans, 0); //initially pass level 0
        return ans;
    }
