#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int s){
     for(int i=0; i<s; i++){
        cout <<  arr[i] << " ";
    }
    cout << endl;
}



void sort_012(int arr[], int n)
{
      int count0=0;
      int count1=0;
      int count2=0;
      
      for(int i=0; i<n; i++){
          
          switch(arr[i]){
              case 0: 
                count0++;
                break;
              case 1: 
                count1++;
                break;
              case 2: 
                count2++;
                break;
          }
      }
      int i=0;
      
      while(count0>0){
          arr[i++]=0;
          count0--;
      }
      
      while(count1>0){
          arr[i++]=1;
          count1--;
      }
      
      while(count2>0){
          arr[i++]=2;
          count2--;
      }
      
         
}
    
    
int main()
{
    int arr[100];
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort_012(arr,n);
    
    print(arr,n);
    return 0;
}
