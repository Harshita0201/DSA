void convertToDoublyLL(TreeNode<int> *root, TreeNode<int>* &head)
{
     //base case
    if(root == NULL)
        return ;
    
    //recursive call to convert right subtree into DLL
    convertToDoublyLL(root->right, head);
    
     //adjust links
    root->right = head;
    
    if(head != NULL)
        head->left = root;
    
    head = root;
    //recursive call to convert left subtree into DLL
    convertToDoublyLL(root->left, head);
}



TreeNode<int>* mergeTwoSortedLL(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    return head;
}

int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    if(n<=0 || head == NULL)
    {
        return NULL;
    }
    
    //create left subtree of first n/2 nodes
    TreeNode<int>* left = sortedLLToBST(head, n/2);
    
    //create root node
    TreeNode<int>* root = head;
    root->left = left;
    
    //traverse LL ahead
    head = head->right;
    
    //create right subtree
    root->right = sortedLLToBST(head, n- n/2 - 1);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    //step1: convert BST into sorted LL- inplace
    //convert first bst1 into sorted LL
    TreeNode<int>* head1 = NULL;
    convertToDoublyLL(root1, head1);
    head1->left = NULL;
    //convert second bst2 into sorted LL
    TreeNode<int>* head2 = NULL;
    convertToDoublyLL(root2, head2);
    head2->left = NULL;
    //step 2: merge the two sorted LL
    TreeNode<int> *head = mergeTwoSortedLL(head1, head2);
    
    //step 3: convert sorted LL into BST
    return sortedLLToBST(head, countNodes(head));

}
