//Given two 32-bits numbers N and M, and two positions i and j, WAP to set all bits between i and j in N equal to M (such that M becomes substring of N) located at i and starting at j)
#include <bits/stdc++.h>
using namespace std;
int clearRangeItoJ(int n, int i, int j){
    //mask st there are 0s in range i to j and rest 1s
    int a=(-1)<<j+1; //all 1s, and 0s from jth pos onwards
    int b= (1<<i)-1;//1 at last i bits
    int mask=a|b;
    int res=n&mask;
    return res;
}
int replaceBitsInNByM(int n, int m, int i, int j){
    int n_=clearRangeItoJ(n, i, j);
    int mask=m<<i;
    int ans=n_|mask;
    return ans;
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    int i, j;
    cin >> i >> j;
    int res= replaceBitsInNByM(n, m, i, j);
    cout << res << endl;

    return 0;
}
