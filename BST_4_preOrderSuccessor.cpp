
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

Node *minVal(Node *root){
    Node *temp=root;
    while(temp->left!=NULL){ //traverse to extreme left
        temp=temp->left;
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

Node * findSuccessor(Node *root, Node *suc, int x){
    //base case
    if(root==NULL){
        return suc;
    }
    
    //if node with x or key is found, the successor is the minimum value in it's right subtree or left most child in left subtree
    if(root->data == x){
        if(root->right!=NULL){
            return minVal(root->right);
        }
    }else if(root->data > x){//if x is < root goto to left 
        // update successor to the current node before recursing in the left subtree
        suc = root;
        return findSuccessor(root->left, suc, x);
    }else{//x is > root goto to right 
        return findSuccessor(root->right, suc, x);
    }
    
    return suc; // predecessor does not exists of given key x
    
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
  
  Node *suc=NULL;
  Node *successor = findSuccessor(root, suc, x);
  cout << "Inorder successor of " << x << " is :" << successor->data << endl;

  
  return 0;
  
}
  
