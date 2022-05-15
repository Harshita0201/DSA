 void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node * solve(int in[],int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        //base case
        //if whole preorder array is covered or traversed all index
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        
        //root element
        int element=pre[index++];
        Node *root= new Node(element); //create node of this element
        
        //find pos of this root elem in Inorder array
       int position=nodeToIndex[element];
       
       //recursive calls to build left and right of root in BT
       root->left=solve(in, pre, index, inOrderStart, position-1, n, nodeToIndex);
       root->right=solve(in, pre, index, position+1, inOrderEnd, n, nodeToIndex);
       
       return root;
       
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex=0;
        map<int, int> nodeToIndex;
        //create node to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans=solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
        
    }
