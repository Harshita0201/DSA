class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        //base case if leaf node
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        
        int ans = 1+ max(left, right);
        return ans;
    }
};
