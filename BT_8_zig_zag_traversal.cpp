vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	if(root==NULL){
    	    return result;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true; // left to right traversal flag
    	
    	while(!q.empty()){
    	    int size= q.size();
    	    
    	    //temporary vector of size of queue
    	    vector<int> ans(size);
    	    
    	    //level process
    	    for(int i=0; i<size; i++){
    	        Node *temp= q.front();
    	        q.pop();
    	        
    	        //normal (L-R) insert or reverse (R-L) insert
    	        int index = leftToRight ? i : size-i-1;
    	        ans[index]=temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left); //if left children present
    	        }
    	        if(temp->right){ //if right children present
    	            q.push(temp->right);
    	        }
    	    }
    	    
    	    //change direction of traversal after 1 level complete
    	    leftToRight=!leftToRight;
    	    
    	    //push ans vector into final result
    	    for(auto i:ans){
    	        result.push_back(i);
    	    }
    	 }
    	 
    	 return result;
    }
