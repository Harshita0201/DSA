// On(n^2) soltuin->

// class Solution {
//   public:
//   int height(Node* root){
//       if(root==NULL){
//           return 0;
//       }
//       int left=height(root->left);
//       int right=height(root->right);
//       int ans=1+max(left,right);
//       return ans;
//   }
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         // Your code here
//         if(root==NULL){ // no node
//             return 0;
//         }
        
//         //recursive calls
//         int op1=diameter(root->left); //diameter from left 
//         int op2=diameter(root->right); //diameter from right 
//         int op3=height(root->left) + 1+ height(root->right); //diamter combo from from left and right
        
//         int ans=max(op1, max(op2, op3)); // max of either of above options
        
//         return ans;
//     }
// };


//O(n) solution
class Solution {
  public:
     pair<int, int> diameter_fast(Node* root){
         if(root==NULL){ //if no node
             pair<int, int> p= make_pair(0,0);
             return p;
         }
          
         //recursive calls for left and right parts 
         pair<int, int> left= diameter_fast(root->left);
         pair<int, int> right= diameter_fast(root->right);
         
         int op1= left.first; //left diameter (inside the pair fisrt int is for diameter)
         int op2= right.first; //right diamter
         
         int op3=left.second + right.second +1; //left hight + right height +1 
         
         pair<int, int> ans;
         ans.first=max(op1, max(op2, op3)); // max of all diameters
         ans.second=max(left.second, right.second) + 1; // max of all hieghts
         
         return ans;
     }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameter_fast(root).first; //return max diameter
    }
};
