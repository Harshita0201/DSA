/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second){
	//if only 1 element present in first linkedd list
	if(first->next==NULL){
		first->next=second; //put second list ahead of first
		return first;
			
	}
    Node<int>* curr1=first;
	Node<int>* next1=first->next;
	Node<int>* curr2=second;
	Node<int>* next2=curr2->next;
	while(next1!=NULL && curr2!=NULL){
	   //if <curr1->data <= curr2->data <= next1->data
	   if((curr2->data >= curr1->data) && (curr2->data<= next1->data)){
	   	  //insert curr2 btw curr1 and next1
		  curr1->next=curr2;
		  next2=curr2->next;
		  curr2->next=next1;
		   
		  //update pointers or move ahead
		  curr1=curr2;
		  curr2=next2; 
	   }else{ //move pointers ahead curr1 and next1
		   curr1=next1;
		   next1=next1->next;
		   
		   if(next1==NULL){ //if first list ends, put linked list 2 ahead of 1, as 2 is already sorted and rest elements are large
			   curr1->next=curr2;
			   return first;
		   }
	   }
	}
	
	return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
	if(first==NULL){
		return second;
	}
	if(second==NULL){
		return first;
	}
	
	if(first->data<second->data){
		return solve(first,second);
	}else{
		return solve(second, first);
	}
	
}
