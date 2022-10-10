// We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// N < 10^5

// Output Format
// Output a single line containing the unique number

// Sample Input
// 7
// 1 1 1 2 2 2 3
// Sample Output
// 3

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num;
	int cnt[64]={0}; //o(1) space as no 64 is constant 
	for(int i=0; i<64; i++){
		cin >> num;
		
		int j=0;
		//extract the last bit of the num and store it into cnt arr 
		//cnt array stores the sum of set bits of all the input numbers
		while(num>0){
			int last_bit=(num&1);
			cnt[j]+=last_bit;
			j++;
			//update number
			num=num>>1; //right shift  number to remove last bit
		}
	}
		//reduce cnt array to binary format of number and convert parallely into decimal  format
		int ans=0;
		int p=1; //base 2^0
		for(int i=0; i<64; i++){
			cnt[i]=cnt[i]%3;

			ans+=cnt[i]*p;
			//update power
			p=p*2;
		}

		cout << ans << endl;
	
	return 0;
}

//TC:O(1)    SC:O(1)
