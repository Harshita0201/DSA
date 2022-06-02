void heapify(vector<int> &arr, int n, int i){
           int smallest=i; //index of the current element to be proccessed
           int left=2*i+1; //index of left child
           int right=2*i+2; //index of right child
           
           //compare with left child
           if(left<n && arr[smallest] > arr[left]){
               smallest=left; //update index
           }
           
           //compare with right child
           if(right<n && arr[smallest] > arr[right]){
               smallest=right; //update index
           }
           
           if(smallest!=i){//if index got updated
              swap(arr[smallest], arr[i]); //swap 
              //check for other elements
              heapify(arr, n, smallest); 
           }
    
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n= arr.size();
    for(int i=n/2-1; i>=0; i--){ 
        heapify(arr, n, i);
    }
    
    return arr;
}
