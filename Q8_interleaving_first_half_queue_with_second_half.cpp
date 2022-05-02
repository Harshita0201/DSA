void interLeaveQueue(queue < int > & q) {
    // Write your code here.
	stack<int> s;
	queue<int> newQ;
	int half=q.size()/2;
	for(int i=0;i<half; i++){
		int ele=q.front();
		q.pop();
		newQ.push(ele);
	}
	while(!newQ.empty()){
		int ele=newQ.front();
		newQ.pop();
		q.push(ele);
		ele=q.front();
		q.pop();
		q.push(ele);
	}
	
	
}
