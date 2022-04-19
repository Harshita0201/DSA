/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL){
		return head;
	}
	unordered_map<int, int> m;
	Node *curr=head;
	m[curr->data]=1;
	Node *prev=curr;
	curr=curr->next;
	while(curr!=NULL){
		if(m[curr->data]){
			prev->next=curr->next;
			free(curr);
		}else{
			m[curr->data]=1;
			prev=curr;
		}
		curr=curr->next;
	}
	return head;
}
