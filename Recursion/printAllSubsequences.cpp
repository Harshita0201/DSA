//given an array print all possible subsequences of that array.
//subsequnce is a non contigious or contigious part of array, in which elements ordering matters.

#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int>&ds, int arr[], int n){
    if(ind==n){
        for(auto it:ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    
    //include the element at index ind
    ds.push_back(arr[ind]);
    solve(ind+1, ds, arr, n);
    ds.pop_back();// to exclude at next step 
    solve(ind+1, ds, arr, n);
}
int main()
{
    int arr[]={1, 2, 3};
    
    int n=3;
    vector<int> ds;
    solve(0, ds, arr, n); // initially index 0

    return 0;
}
