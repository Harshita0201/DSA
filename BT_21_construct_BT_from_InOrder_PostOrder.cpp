 void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node * solve(int in[],int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        //base case
        //if whole preorder array is covered or traversed all index
        if(index<0 || inOrderStart>inOrderEnd){ 
            return NULL;
        }
        
        //root element
        int element=post[index--]; //as in postorder we are starting from the end
        Node *root= new Node(element); //create node of this element
        
        //find pos of this root elem in Inorder array
       int position=nodeToIndex[element];
       
       //recursive calls to build left and right of root in BT
       root->right=solve(in, post, index, position+1, inOrderEnd, n, nodeToIndex);
       root->left=solve(in, post, index, inOrderStart, position-1, n, nodeToIndex);
      
       
       return root;
       
        
    }
    Node* buildTree(int in[],int post[], int n)
    {
        // Code here
        int postOrderIndex=n-1;
        map<int, int> nodeToIndex;
        //create node to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans=solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
        
    }
