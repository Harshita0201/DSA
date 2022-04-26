// You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
// We can only use the following functions on this stack S.
// is_empty(S) : Tests whether stack is empty or not.
// push(S) : Adds a new element to the stack.
// pop(S) : Removes top element from the stack.
// top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
// Note :
// 1) Use of any loop constructs like while, for..etc is not allowed. 
// 2) The stack may contain duplicate integers.
// 3) The stack may contain any integer i.e it may either be negative, positive or zero.



void insertSorted(stack<int> &s, int num){
	//base case
	if(s.empty() || (!s.empty() && s.top()<num)){
		//push the element right next to it's next minimum
		s.push(num);
		return;
	}
	//keep the tos aside
	int n=s.top();
	s.pop();
	
	//recursive call
	insertSorted(s, num);
		
	//push TOS before return
	s.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	//base case if stack is empty
	if(stack.empty()){
		return;
	}
	
	//keep the top element aside
	int num=stack.top();
	stack.pop();
	
	//recursive call
	sortStack(stack);
	
	//insert TOS in sorted order before return
	insertSorted(stack,num);
}
