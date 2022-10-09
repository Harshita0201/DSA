// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
    int ans=0;
    while(n>0){
        ans+=(n&1);
        n=n>>1; //right shift n by 1 to remove last bit
    }
    return ans; 
} //TC: O(LOGN)+1 BCZ it extracts all bits in number and a number k will have Logn bits 
int countSetBitsFast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1); //removes set bits from right to left
        ans++;
    }
    return ans;
}// TC:O(num of set bits)
int main(){
    int n;
    cin >> n;
    
    int a1=countSetBits(n);
    int a2=countSetBitsFast(n);
    cout << a1 << endl;
    cout << a2 << endl;
    
    //---USING BUILT IN FUNCITON---
    cout << __builtin_popcount(n) << endl;
    return 0;
}
