
#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;


    Node (int data)
  {				//constructor
    this->data = data;
    this->left = NULL;
    this->right = NULL;
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

void levelOrderTraversal (Node * root)
{
  queue < Node * >q;
  q.push (root);
  q.push (NULL);		//after 1 level 

  while (!q.empty ())
    {
      Node *temp = q.front ();
      q.pop ();
      if (temp == NULL)
	{
	  //old level of traveral completed
	  cout << endl;

	  if (!q.empty ())
	    {			//we have pushed left n right child of previous node 
	      q.push (NULL);	// push null to mark seperator, aas level completed
	    }
	}
      else
	{
	  cout << temp->data << " ";
	  if (temp->left)
	    {			//if left child of temp exists
	      q.push (temp->left);
	    }
	  if (temp->right)
	    {			//if right child of temp exists
	      q.push (temp->right);
	    }
	}
    }
}

Node *insertIntoBST (Node * root, int data)
{
  //base case 
  if (root == NULL)
    {
      root = new Node (data);
      return root;
    }

  if (data > root->data)
    {				//insert into right 
      root->right = insertIntoBST (root->right, data);
    }
  else
    {
      root->left = insertIntoBST (root->left, data);
    }

  return root;
}


void takeInput (Node * &root)
{
  int data;
  cin >> data;

  while (data != -1)
    {
      root = insertIntoBST (root, data);
      cin >> data;
    }
}

Node *minVal(Node *root){
    Node *temp=root;
    while(temp->left!=NULL){ //traverse to extreme left
        temp=temp->left;
    }
    return temp;
}

Node *maxVal(Node *root){
    Node *temp=root;
    while(temp->right!=NULL){ //traverse to extreme right
        temp=temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int x){
    //base case 
    if(root==NULL){
        return root;
    }
    
    //key found
    if(root->data==x){
        //3 cases
        //case 1, 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // case 2, one child, either left or right
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left; //save link before deletion
            delete root;
            return temp;
        }
        //similarly for right child
        if(root->left==NULL && root->right!=NULL){
            Node *temp=root->right; //save link before deletion
            delete root;
            return temp;
        }
        
        //case 3, both left and right child present
        if(root->left!=NULL && root->right!=NULL){
            //find Minimum from the right subtree
            int mini = minVal(root->right)->data;
            //replace mini with root->data
            root->data= mini;
            //delete mini from right subtree
            root->right = deleteFromBST(root->right, mini);
            
            return root;
        }
    }else if(root->data > x){ // x is smaller, goto left subtree
        root->left= deleteFromBST(root->left, x);
    }else{ //x is greater, goto right subtree
        root->right= deleteFromBST(root->right, x);
    }
    return root;
}
int main ()
{
  Node *root = NULL;

  cout << "Enter data to create BST" << endl;
  takeInput (root);

  cout << "The final BST is " << endl;

  levelOrderTraversal (root);

 cout << "Printing inorder traversal " << endl;
  inOrder(root);
  cout << endl;
  

  cout << "Printing preorder traversal " << endl;
  preOrder(root);
  cout << endl;
   
  cout << "Printing postorder traversal " << endl;
  postOrder(root);
  cout << endl;

  Node *min=minVal(root);
  Node *max=maxVal(root);
  cout << "Minimum value " << min->data<< endl; 
  
  cout << "Maximum value " << max->data << endl;
  
  deletion
  int d;
  cout << "Enter the data that you want to delete" << endl;
  cin >> d;
  
  root= deleteFromBST(root, 10);
  cout << "AFTER DELETION" << endl;
  
   cout << "The final BST is " << endl;

  levelOrderTraversal (root);

  cout << "Printing inorder traversal " << endl;
  inOrder(root);
  cout << endl;
  

  cout << "Printing preorder traversal " << endl;
  preOrder(root);
  cout << endl;
   
  cout << "Printing postorder traversal " << endl;
  postOrder(root);
  cout << endl;
  
  return 0;
}

