#include <bits/stdc++.h>
using namespace std;
int decimalToBinary(int n){
    int ans=0;
    int p=1;
    while(n>0){
        int last_bit=n&1;
        ans+=p*last_bit;
        p=p*10; //update pwer
        n=n>>1; //discard last bit or update num
    }
    return ans;
}
int main() {
    
    int n;
    cin >> n;
    cout << decimalToBinary(n) << endl;

    return 0;
}
