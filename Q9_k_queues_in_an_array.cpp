
#include <bits/stdc++.h>
using namespace std;

class kQueue{
    private:
       int k;
       int n;
       int *arr;
       int *front;
       int *rear;
       int freeSpot;
       int *next;
       
    public:
       kQueue(int n, int k){
           this->n=n;
           this->k=k;
           arr=new int[n];
           next=new int[n];
           for(int i=0; i<n; i++){
               next[i]=i+1;
           }
           next[n-1]=-1; //last index of next[], i.e no next freeSpot
           front= new int[k];
           rear= new int[k];
           for(int i=0; i<k; i++){
               front[i]=-1;
               rear[i]=-1;
           }
           freeSpot=0; //starting
           
       }
       
       void enqueue(int data, int qn){ //push data to qn queue
           //overflow condition 
           if(freeSpot==-1){
               cout << "No empty space available" << endl;
           }
           
           //find first free index
           int index= freeSpot;
           
           //update freeSpot
           freeSpot=next[index];
           
           //check wheather first element 
           if(front[qn-1]==-1){ //qn-1, bcz 0 index, if qn=1 then in qn  
               front[qn-1]=index; //update front of qn queue
           }else{
               //link new element to prev element
               next[rear[qn-1]]=index;
           }
           
           //update next
           next[index]=-1;
           
           //update
           rear[qn-1]=index;
           
           //push element
           arr[index]=data;
       }
       
       int dequeue(int qn){//pop / remove from qn queue
           //check underflow condition
           
           if(front[qn-1]==-1){
               cout <<"No element, underflow condition" << endl;
               return -1;
           }
           
           //find index to pop
           int index=front[qn-1]; //pop from front in queue therefore index is of first element
           
           //move front ahead;
           front[qn-1]=next[index];
           
           //manange freeSpots
           next[index]=freeSpot;
           freeSpot=index; // at the index of removed element
           
           return arr[index];
       }
};

int main()
{
    kQueue q(10, 3); //size of arr=10 or n=10 and  queues are 3 or  k=3
    q.enqueue(10,1); //push 10 in 1
    q.enqueue(15,1); //push 15 in 1
    q.enqueue(20,2); //push 20 in 2
    q.enqueue(25,1); //push 25 in 1
    
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}
