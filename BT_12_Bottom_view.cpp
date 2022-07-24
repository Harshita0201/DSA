class Solution {
  public:
    vector <int> bottomView(Node *root) {
       vector<int> ans;
       
       if(root==NULL){
           return ans;
       }
       
       map<int, int> m; //mapping of hd, and node->data
       queue<pair<Node *, int>> q; //node and hd
       
       q.push({root, 0}); //root at hd 0
       
       while(!q.empty()){
           pair<Node *, int> temp=q.front();
           q.pop();
           
           int hd=temp.second;
           Node* node=temp.first;
           
           m[hd]=node->data;//stroe node at hd in map
           
           if(node->left){
               q.push({node->left, hd-1});
           }
           if(node->right){
               q.push({node->right, hd+1});
           }
       }
       
       for(auto i:m){
           ans.push_back(i.second);
       }
       return ans;
    }
};
