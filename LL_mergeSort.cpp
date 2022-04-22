/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* getMid(node* &head){
	node *slow=head;
	node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
node *merge(node *left, node *right){
	if(left==NULL){
		return right;
	}
	if(right==NULL){
		return left;
	}
	
	node * ans=new node(-1);
	node *temp=ans;
	while(left!=NULL && right!=NULL){
		if(left->data < right->data){
			temp->next=left;
			temp=left;
			left=left->next;
		}else{
			temp->next=right;
			temp=right;
			right=right->next;
		}
	}
	while(left!=NULL){
		temp->next=left;
		temp=left;
		left=left->next;
	}
	while(right!=NULL){
		temp->next=right;
		temp=right;
		right=right->next;
	}
	
	ans=ans->next;
	return ans;
}
node* mergeSort(node *head) {
    // Write your code here.
	//base case //if 0 or 1 element
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	//break the linked list into two halves
	node* mid=getMid(head);
	node *left= head;
	node *right=mid->next;
	mid->next=NULL; //split
	
	//recursive calls to sort both the linked list
	left=mergeSort(left);
	right=mergeSort(right);
	
	//merge both the linked list
	node *result=merge(left, right);
	
	return result;
}
