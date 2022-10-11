// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int fastExponention(int a, int n){
    //in O(logn) time we extract the bits from n ...eg if n=5
    //in binary 101...starting from right to left
    //if it is a set bit(1) then multiply ans(initislly 1) by a, then go to next bit and mulitply a=a*a
    //since a number will have logn bits therefore this technique uses logn time
    
    int ans=1;
    while(n){
        int lastBit = n&1;
        if(lastBit){
            ans=ans*a;
        }
        a=a*a; //square up the value of a
        n=n>>1;//discard last bit
    }
    return ans;
}
int main() {
    //----To compute a^n----
    int a, n;
    cin >> a >> n;
    cout << "Ans is = " << fastExponention(a,n) << endl; 
    return 0;
}
