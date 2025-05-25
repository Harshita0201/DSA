#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row;
    cin >> row; 
    int **arr= new int*[row]; // jaggered array
    
    int *colSize = new int[row];//number of columns in each row
    
    for(int i=0; i<row; i++){
        cout << "enter number of cols for this row " << endl;
        int cs;
        cin >> cs;
        colSize[i]=cs;
        
        arr[i] = new int[cs];//array of no of cols at ith row
        cout << "enter elements for this array = " << endl;
        for(int j=0; j<cs; j++){
            cin >> arr[i][j]; 
        }
    }
    
    cout << "your jaggered array is =" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<colSize[i]; j++){
            cout << arr[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
    
    for(int i=0; i<row; i++){
        delete []arr[i]; // delete all cols
    }
    delete []arr; // delete all rows 
    delete []colSize; //delete colSize arr
}
