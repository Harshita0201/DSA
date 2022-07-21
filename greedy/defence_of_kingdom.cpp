//https://www.spoj.com/problems/DEFKIN/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t, w, h, n;
    int x[40010];
    int y[40010];
    cin >> t;
    while(t--){
        cin >> w >> h >>  n;
        
        for(int i=0; i<n ;i++){
            cin >> x[i] >> y[i];
        }
        
        //sort the x and y cordinates of n towers
        sort(x, x+n);
        sort(y, y+n);
        
        //initially max distances btw consecutive x's and y's
        int dx=x[0]-1;
        int dy=y[0]-1;
        
        for(int i=1; i<n; i++){
           dx=max(dx, x[i]-x[i-1]-1); // diff of sorted cordinates of x 
           dy=max(dy, y[i]-y[i-1]-1);
        }
        
        //corner cases (last tower to grid end)
        dx=max(dx, w-x[n-1]); //width of grid - x cord of largest x of tower loc
        dy=max(dy, h-y[n-1]); //hieght of grid - y cord of largest y of tower loc
        
        //max area-->
        cout << dx*dy << endl;
        
    }

    return 0;
}
