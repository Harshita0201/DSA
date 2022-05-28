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



Node *maxVal(Node *root){
    Node *temp=root;
    while(temp->right!=NULL){ //traverse to extreme right
        temp=temp->right;
    }
    return temp;
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

Node * findPredecessor(Node *root, Node *pred, int x){
    //base case
    if(root==NULL){
        return pred;
    }
    
    //if node with x or key is found, the predecessor is the maximum value in it's left subtree or right most child in left subtree
    if(root->data == x){
        if(root->left!=NULL){
            return maxVal(root->left);
        }
    }else if(root->data > x){//if x is < root goto to left 
        return findPredecessor(root->left, pred, x);
    }else{//x is > root goto to right 
    
        // update predecessor to the current node before recursing
        // in the right subtree
        pred = root;
        return findPredecessor(root->right, pred, x);
    }
    
    return pred; // predecessor does not exists of given key x
    
}


int main ()
{
  Node *root = NULL;

  cout << "Enter data to create BST" << endl;
  takeInput (root);

  cout << "The final BST is " << endl;

  levelOrderTraversal (root);
  
  int x;
  cout << "Enter x " << endl;
  cin >> x;
  
  Node *pred=NULL;
  Node *predec = findPredecessor(root, pred, x);
  cout << "Inorder predecessor of " << x << " is :" << predec->data << endl;
//   cout << "Inorder successor of " << x << " is :" << suc->data << endl;
  
  return 0;
  
}
  
