// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.
// Try to do this without using any other data structure.

void solve(stack<int>& s, int x){
	//base case
	//if stack is empty
	if(s.empty()){
		s.push(x); //push at bottom
		return;
	}
	
	//keep the top element aside
	int ele=s.top();
	s.pop();///remove before next recursion
	
	//recursive call
	solve(s, x);
	
	//push back the top element before return
	s.push(ele);

}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
	solve(myStack, x); //recursion function 
	return myStack;
}
