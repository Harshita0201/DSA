void solve(Node* root, int k, int &count, vector<int> path){
        //base case
        if(root==NULL){
            return;
        }
        
        path.push_back(root->data);
        
        //left and right recursive calls
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        int size=path.size();
        int sum=0;
        for(int i=size-1; i>=0; i--){
            sum+=path[i]; //update sum
            if(sum==k){ //if match found
                count++; //update count
            }
        }
        path.pop_back(); //remove last node data before returning
    }
    
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path; //for path of nodes
        int count=0;
        solve(root, k, count, path);
        return count;
    }
