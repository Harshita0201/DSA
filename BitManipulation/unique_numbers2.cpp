//coding blocks
//We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. 
//Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// n < 10^5

// Output Format
// Output a single line containing the unique numbers separated by space

// Sample Input
// 4
// 3 1 2 1
// Sample Output
// 2 3


#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[100005];
	int res=0; //will have xor of numbers that are unique i.e a^b
	int num;
	for(int i=0; i<n; i++){
		cin >> num;
		arr[i]=num;
		res=res^num;
	}
	//find the first set bit in res
	int temp=res;
	int pos=0;
	while((temp&1)!=1){
		pos++;
        temp=temp>>1; //right shift to discard last bit 
	}

	//create mask with bit at pos
	int mask = (1 << pos);

	//find all numbers which has set bit at position "pos"
	int a=0;
	int b=0;
	for(int i=0; i<n; i++){
		if((arr[i]&mask)>0){
			a=a^arr[i]; //2 repeated will cancel and original unique a will be retrieved
		}
	}
	b=res^a; // res=a^b therefore a^b^a will give us b
	cout << min(a,b)  << " " << max(a,b) << endl;
	return 0;
}
