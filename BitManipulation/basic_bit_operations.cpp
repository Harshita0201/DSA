// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isEven(int n){
    return (n&1); //will return 1 or true if n is odd, else false or  0
}
int getBit(int n, int i){
    //1&0 = 0 1&1=1
    // create mask 
    int mask = 1<<i; //take 1 to ith postion, therefore left shift
    int bit=(n&mask)>0?1:0; // get the ith bit, if the & is greater than 1 then it is 1 else 0
    return bit;
}
int setBit(int n, int i){
    //set bit means to make bit 1 
    //1|0=1 1|1=1
    // create mask
    int mask= 1<<i; //left shift 1 to ith pos
    int res=n|mask;
    return res;
}

int clearBit(int n, int i){
    // clear bit means to make bit 0 from ith pos
    //1&0=0, 0&0=0;
    //to retain all other bits ->if 1, 1&1=1, if 0 1&0=0
    int mask=~(1<<i); //take 1 to ith pos, NOT of---1--, to get 0 at i th pos and rest 1
    int res=n&mask;
    return res;
}
void updateBit(int &n, int i, int v){
    // clear bit at ith pos
    // new cleared bit n OR with mask
    int clear_bit_n = n&(~(1<<i));
    n= clear_bit_n | (v<<i);
    
}

int clearLastIBits(int n, int i){
    //retain all numbers till ith pos - therefore have 1
    //clear last i bits there have 0
    //-1 is all 1's ...left shift it to i pos to get 0s at last i position 
    //to discard: 1&-0=0 0&0=0, to retain:1&1=1, 1&0=0
    int mask = -1<<i;
    int num=n&mask; 
    return num; 
}

int clearBitsInRange(int n,int i,int j){
    //a: all 1's till jth pos
    //b: all 0's except from ith pos
    //a|b -> create a mask which will have all 0's from j to i left to right and all 1's 
    int a=-1<<(j+1); // all 1's left shift by j+1 means 0 from j pos onwards
    int b=(1<<i)-1; // all 1's from ith pos left to 0
    //1<<i 0 from last i bits and, -1 means 1 inplace of 0's
    int mask=a|b;
    int num=n&mask;
    return num;
}

int main() {
    
    int n;
    cin >> n;
    int i;
    cin >> i;
    
    //------ODD EVEN----------
    // int a=isEven(n);
    // if(a){
    //     cout << "NO, is not even" << endl;
    // }else{
    //     cout << "Yes, it is even" << endl;
    // }


//  //------------TO get the ith bit from N from right---------
//   int res=getBit(n, i);
//   cout << i << " bit from right position is = " << res << endl;
   
//   //--------To set the ith bit from right position -----------
//   int ans=setBit(n, i);
//   cout << "After set bit, number becomes = " << ans << endl;
   
//   //-------To clear bit from ith position form right------------
//   int res=clearBit(n, i);
//   cout  << "After clear bit, number becomes = " << res <<endl;
   
   
//   //--------To update the ith bit from right pos---------
//   int v;
//   cin >> v;
//   updateBit(n, i, v);
//   cout << "after update number becomes = " << n << endl;


// // ---------To clear last i bits
//      
//      int ans=clearLastIBits(n, i);
//      cout << ans << endl;
     
     //to clear bits int range of i to j from right to left 
     int j;
     cin >> j;
     int res=clearBitsInRange(n, i, j);
     cout << res << endl;
     return 0;
}
