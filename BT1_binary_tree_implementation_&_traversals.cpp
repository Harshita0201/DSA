#include <bits/stdc++.h>
using namespace std;
class Node{
   public:
      int data;
      Node *left;
      Node *right;
   
   
      Node(int d){
          this->data= d;
          this->left=NULL;
          this->right=NULL;
      }
      
};

void inOrder(Node *root){ //LNR
    if(root==NULL){ //base case
        return; 
    }
    inOrder(root->left); //L
    cout << root->data << " "; //N
    inOrder(root->right);//R
    
}


void preOrder(Node *root){ //NLR
    if(root==NULL){ //base case
        return;
    }
    cout << root->data << " "; //N
    preOrder(root->left); //L
    preOrder(root->right);//R
    
}


void postOrder(Node *root){ //LRN

    if(root==NULL){ //base case
        return;
    }
    
    postOrder(root->left); //L
    postOrder(root->right);//R
    cout << root->data << " "; //N
    
}

void reverseLevelOrder(Node * root){
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);
    q.push(NULL); //1 level complet
    
    while(!q.empty()){
        Node *temp=q.front();
        q.pop(); //pop from queue
        s.push(temp);//push into stack
        
        if(temp==NULL){
            //old level completed 
           // cout << endl; //seperator 
            s.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
            
        }else{
            
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    
    while(!s.empty()){
        
        Node *temp=s.top();
        s.pop();
        if(temp==NULL){
            cout << endl; //seperator
        }else{
        cout << temp->data << " ";
        }
    }
    
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //after 1 level 
    
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            //old level of traveral completed
            cout << endl;
            
            if(!q.empty()){//we have pushed left n right child of previous node 
                q.push(NULL); // push null to mark seperator, aas level completed
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){//if left child of temp exists
                q.push(temp->left);
            }
            if(temp->right){//if right child of temp exists
                q.push(temp->right);
            }
        }
    }
}

Node* buildTree(Node *root){
    int data;
    cout <<" Enter the data : " << endl;
    cin >>data;
    root= new Node(data);
    
    if(data==-1){ //null state or element in node
        return NULL;
    }
    
    cout << "Enter data for inserting in left of  " << data << ":"  << endl;
    root->left=buildTree(root->left); //recursive call 
   // we return when user inputs -1 in inserting data to the left
    
    cout << "Enter data for inserting in right of "  << data << ":"  << endl;
    root->right=buildTree(root->right); //recursive call
    
    // we return when user inputs -1 in inserting data to the right
    
    return root;
}

void buildFromLevelOrder(Node* &root){
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;
    root=new Node(data);
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        
        cout << "Enter data for left of " << temp->data << endl;
        int Leftd;
        cin >> Leftd;
        if(Leftd!=-1){
            temp->left=new Node (Leftd);
            q.push(temp->left);
        }
        
        cout << "Enter data for right of " << temp->data << endl;
        int Rightd;
        cin >> Rightd;
        if(Rightd!=-1){
            temp->right=new Node (Rightd);
            q.push(temp->right);
        }
        
        
    }
}


int main()
{
    Node * root=NULL; //initially
    //now to build tree
    //root=buildTree(root);
    buildFromLevelOrder(root);
    
    levelOrderTraversal(root);
    cout << "Reverse order traversal " << endl;
    reverseLevelOrder(root);
    cout << endl;
    cout << "Inorder Traversal :" << endl;
    inOrder(root);
    cout << endl;
    cout << "Preorder Traversal :" << endl;
    preOrder(root);
    cout << endl;
    cout << "Postorder Traversal :" << endl;
    postOrder(root);
    cout << endl;
    return 0;
}


