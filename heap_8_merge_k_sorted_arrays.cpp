#include<queue>
class node{
    public:
       int data;
       int i;
       int j;
       
       node(int data, int row, int col){
           this->data= data;
           i=row;
           j=col;
       }
};

class compare{
    public:
       bool operator()(node *a, node *b){
           return a->data > b->data;
       }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, compare> min_heap;
    
    //step 1: insert all k arrays first element into the min_heap
    for(int i=0; i<k; i++){
        node *tmp= new node(kArrays[i][0], i, 0);
        min_heap.push(tmp);
    }
    
    vector<int> ans;
    
    //step 2
    while(min_heap.size() > 0){
        node *tmp=min_heap.top();
        //stroe the minimum element
        ans.push_back(tmp->data);
        min_heap.pop();
        
        int i=tmp->i;
        int j=tmp->j;
        
        //push the next minimum from the kth array
        if(j+1 < kArrays[i].size()){
            node *next=new node(kArrays[i][j+1], i, j+1);
            min_heap.push(next);
        }
    }
    
    return ans;
}
