//https://www.spoj.com/problems/BUSYMAN/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
    //based on ending time
    return p1.second<p2.second;
}
int main() {
    
    int t, n, s, e;
    cin >> t;
    vector<pair<int, int>> v;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> s >> e;
            v.push_back({s, e});
        }
        
        //sort the vector of start and finish time based on finish time
        sort(v.begin(), v.end(), compare);
        
        //start picking activites
        //always pick the first activity
        int res=1; //num of activities picked so far
        int fin=v[0].second; //last finish time
        
        //iterate over the other activites
        for(int i=1; i<n; i++){
            //pick activity if the start time of the first is more than the last activites finish time
            if(v[i].first>=fin){
                res++; //pick activity
                fin=v[i].second;//update last finish time
            }
        }
        cout << res << endl;
        v.clear();
        
    }

    return 0;
}
