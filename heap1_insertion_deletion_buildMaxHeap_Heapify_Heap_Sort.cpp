#include <iostream>
using namespace std;

class heap{
    public:
       int size;
       int arr[100];
       
       heap(){
           arr[0]=-1;
           size=0;
       }
       
       void insert(int data){
           size = size+1; //increase size of arr
           int index = size; //new pos to insert
           arr[index] = data; //insert at new pos
           
           while(index>1){ //for all the nodes of CBT or all elements of heap
               int parent= index/2; //index of parent
               
               if(arr[parent] < arr[index]){ //if new node inserted is greater than it's parent then swap
                   swap(arr[parent], arr[index]);
                   index = parent; //check for all values before parent
               }else{
                   return; //remain same
               }
           }
           
       }
       
       void print(){
           for(int i=1; i<=size; i++){ 
               cout << arr[i] << " ";
           }
           cout << endl;
       }
       
       void deleteFromHeap(){
           if(size==0){
               cout << "Nothing to delete" << endl;
               return;
           }
           
           //replace the first or root element with last element of heap
           arr[1]=arr[size];
           
           //delete the last element
           size--;
           
           //make the new root move to it's correct postion
           int i=1;
           while(i<size){
               int leftIndex=2*i;
               int rightIndex=2*i+1;
               
               if(leftIndex < size && arr[i] < arr[leftIndex]){ // if left child is greater
                   swap(arr[i], arr[leftIndex]);
                   i=leftIndex; // move index ahead for further comparisons
               }else if(rightIndex < size && arr[i] < arr[rightIndex]){ //if right child is greater
                   swap(arr[i], arr[rightIndex]);
                   i=rightIndex;
               }else{
                   return; //remains same
               }
           }
       }
       
       
};

void heapify(int arr[], int n, int i){
           int largest=i; //index of the current element to be proccessed
           int left=2*i; //index of left child
           int right=2*i+1; //index of right child
           
           //compare with left child
           if(left<=n && arr[largest] < arr[left]){
               largest=left; //update index
           }
           
           //compare with right child
           if(right<=n && arr[largest] < arr[right]){
               largest=right; //update index
           }
           
           if(largest!=i){//if index got updated
              swap(arr[largest], arr[i]); //swap 
              //check for other elements
              heapify(arr, n, largest); 
           }
    
}
void heapSort(int arr[], int n){
    int t=n; //number of nodes in heap
    
    while(t>1){ //for all nodes
        //step 1, swap first and last elements
        swap(arr[t], arr[1]);
        
        //step 2: reduce size
        t--;
        
        //step3: place the new root element at it's correct postion
        heapify(arr,t, 1); //heapify for new size 
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.deleteFromHeap();
    h.print();
    
    int arr[6]={-1, 54, 53, 55, 52, 50};
    int  n=5;
    
    //heap creation or buildheap maxheap
    for(int i=n/2; i>0; i--){ 
        heapify(arr, n, i);
    }
    
    cout << "After heapify " << endl;
    for(int i=1; i<=n; i++){ 
               cout << arr[i] << " ";
    }
    cout << endl;
           
    heapSort(arr, n);
    
    cout << "After sorting " << endl;
    for(int i=1; i<=n; i++){ 
               cout << arr[i] << " ";
    }
    cout << endl;
           
           
    return 0;
}
