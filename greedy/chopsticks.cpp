//https://www.codechef.com/problems/TACHSTCK

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int n, d;
	cin >> n >> d;
	
	vector<int> chops(n);
	
	
	for(int i=0; i<n; i++){
	   cin >> chops[i];
	}
	
	sort(chops.begin(), chops.end());
	
	int pair=0;
	for(int i=0; i<n-1; i++){//iterate on sorted list of chopsticks
	   if(chops[i+1]-chops[i]<=d){ //if the diff btw nearest two chhops is less than or equal to given d then pair them and move to next ele of pair
	       i++;
	       pair++;
	   }
	}
	cout << pair << endl;
	return 0;
}
