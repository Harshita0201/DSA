#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
//     vector<int> v;
//     int n=arr.size();
//     for(int i=0; i<n; i++){
//         int sum=0;
//         for(int j=i; j<n; j++){
//             sum+=arr[j];
//             v.push_back(sum);                              o(n^2) Time complexity
//         }
//     }
    
//     sort(v.begin(), v.end());
    
   // return v[v.size()-k];
    
    priority_queue<int, vector<int>, greater<int>> mini;
    int n=arr.size();
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    
    return mini.top();
}
