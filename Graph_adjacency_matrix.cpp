#include<iostream>
using namespace std;
int main(){
    int n, m, u, v;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    
    int A[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=0;
        }
    }
    
    for(int i=0; i<m; i++){
        cin >> u >> v;
        A[u][v]=1;
        //A[v][u]=1;// in case of directed we remove this 
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << " ";
        }
        cout <<endl;
    }
    
    return 0;
    
}
