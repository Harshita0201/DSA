// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(int n){
    int base=1; //2^0
    int ans=0;
    while(n){
        int digit=n%10;
        n=n/10;
        ans+=digit*base;
        base=base*2;
    }
    return ans;
}
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    cout << binaryToDecimal(n) << endl;

    return 0;
}
