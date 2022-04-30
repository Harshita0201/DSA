class CircularQueue{
	//data members
	int *arr;
	int front;
	int rear;
	int size;
	
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
		size=n;
		arr= new int[size];
		front=rear=-1; //initially both rear and front are -1
		
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //check for overflow conditon
		if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
			return false; //cannot insert
		}else if(front==-1){ //first element
			front=rear=0;
		}else if(rear==size-1 && front!=0){//rear has reached the end of queue and front is not at the start
			rear=0; //to maintian the cyclic nature of queue
		}else{ //normal flow
			rear++;
		}
	    arr[rear]=value; //push/ insert/ enqueue
		return true;
		   
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check for underflow condition 
		if(front==-1){
			return -1; //no element to return
		}
		int ans=arr[front];
		arr[front]=-1; //overwrite to delete
		
		if(front==rear){ //single elemenet
			front=rear=-1;
		}else if(front==size-1){ //front reached the end
			front = 0; //to maintain the cyclic nature of queue
		}else{ //normal flow
			front++;
		}
		
		return ans;
    }
};
