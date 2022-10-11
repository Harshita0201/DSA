//given string print all the subsets/subsequences of the same
//eg: i/p: "abc"
//o/p: "", "a", "b", "c", "ab", "ac", "bc", "abc"
#include<bits/stdc++.h>
using namespace std;
void filterChars(char a[], int n){
    //filter chars ectracts char at pos of binary i
    //eg if i is 5- 101 and a="abc"
    //we extract last bit ->1 and print a[j] if bit 0 then we do not print ..like this ac will be printed
    // j keeps track of pos
    int j=0;
    while(n){
        int lastBit=n&1;
        if(lastBit==1){
            cout << a[j];
        }
        j++; //move ahead
        n=n>>1; //discard last bit
    }
    cout << endl;
    return ;
}
void printSubsets(char a[]){
    int n=strlen(a);
    for(int i=0; i<(1<<n); i++){ //if string length is 3 then there will be 8 subsets (2^n)
        filterChars(a, i);//i is binary 0, 1, 2, 3....2^n
    }
    return;
}
int main(){
    char a[100];
    cin >>a ;
    printSubsets(a);
    return 0;
}
