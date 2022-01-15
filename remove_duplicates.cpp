#include<iostream>
#include<cstring>
using namespace std;
void remove_duplicates(char a[]){
    int l = strlen(a);
    
    if(l==0 || l==1){
        return;
    }
    
    int prev = 0;
    
    for(int current = 1; current<l; current++){
        if(a[current]!=a[prev]){
            prev++;
            a[prev]=a[current];
        }
    }
    a[prev+1]='\0';
    
}
int main(){
    char a[1000];
    cin >> a;
    remove_duplicates(a);
    cout << a << endl;
    return 0;
}
