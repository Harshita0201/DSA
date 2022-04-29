class Queue {
	//data memebers 
	//in case of array implementation 
	int size=100001;
	int *arr;
	int qfront;
	int rear;
	
public:
    Queue() {
        // Implement the Constructor
		int size=100001;
	    arr= new int[size];
		qfront=0; //initially both rear & front at first index, empty queue
		rear=0;
		
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
		if(qfront==rear){
			return true;
		}else{
			return false;
		}
    }

    void enqueue(int data) {
        //check for overflow condition
		if(rear==size){ //full queue
			cout<<"Queue is full" << endl;
		}else{
			arr[rear]=data; //insert at end
			rear++;
		}
    }

    int dequeue() {
        //check for underflow condition
		if(qfront==rear){ //queue is empty
			return -1;
		}else{
			int ans=arr[qfront]; // remove from start
			arr[qfront]=-1; //overwrite to remove element
			qfront++;
			if(qfront==rear){
				qfront=0;
				rear=0;
			}
			return ans;
		}
    }

    int front() {
        // Implement the front() function
		if(qfront==rear){
			return -1;
		}else{
			return arr[qfront];
		}
    }
};
