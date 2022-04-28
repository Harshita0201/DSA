class NStack
{
	int *arr;
	int *next;
	int *top;
	int freeSpot;
	int n, s;//s-size , n-no of stacks
	
public:
    // Initialize your data structure.
    NStack(int N, int S) //S-size , N-no of stacks
    {
        // Write your code here.
		n=N;
		s=S;
		
		arr= new int[s];
		next= new int[s];
		top= new int[n];
		
		//initialise top to -1
		for(int i=0; i<n; i++){
			top[i]=-1;
		}
		
		//initialise next 
		for(int i=0; i<s; i++){
			next[i]=i+1;
		}
		//update last index of next to -1
		next[s-1]=-1;
		
		freeSpot=0; //initially
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
		//check for overflow
        if(freeSpot == -1) {
            return false;
        }
		
		//find index
		int index=freeSpot;
		
		//insert into array
		arr[index]=x;
		
		//update freeSpot
		freeSpot=next[index];
		
	    //update next
		next[index]=top[m-1]; //pointing to previous top 
		
		//update top
		top[m-1]=index;
		
		return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
		//inverse of push
		
		//check underflow conditon
		if(top[m-1]==-1){//empty all stacks
			return -1;
		}
		
		int index=top[m-1];
		
		top[m-1]=next[index];
		
		next[index]=freeSpot;
		
		freeSpot=index;
		
		return arr[index];
    }
};
