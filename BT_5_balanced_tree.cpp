// O(n^2) solution->
// bool isBalanced(Node *root)
//     {
//         //  Your Code here
//         if(root==NULL){
//             return true;
//         }
        
//         //recursive calls for left and right
//         bool left= isBalanced(root->left);
//         bool right= isBalanced(root->right);
        
//         bool diff= abs(height(root->left)- height(root->right)) <=1;
        
//         if(left && right && diff){
//             return true;
//         }else{
//             return false;
//         }
        
        
//     }

//O(n) solution
 pair<bool, int> isBalanced_fast(Node *root){
        if(root==NULL){ //if no root
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        //recursive calls for left subtree and right subtree to satisfy this true condition
        pair<bool, int> left=isBalanced_fast(root->left); 
        pair<bool, int> right=isBalanced_fast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff= abs(left.second-right.second)<=1; //int part depicts hieght in pair <bool, int>
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;//returns height

        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        
       // isBalanced_fast(root);
        return isBalanced_fast(root).first;
    }
