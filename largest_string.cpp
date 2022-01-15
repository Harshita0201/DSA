
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n; 
    
    char current_string[1000];
    char largest_string[1000];
    
    int len=0;
    int largest_len=0;
    
    cin.get();
    
    for(int i=0; i<n; i++){
        
        cin.getline(current_string,1000);
        len=strlen(current_string);
        
        if(len>largest_len){
            largest_len = len;
            strcpy(largest_string, current_string);
        }
        
    }

    cout << "Largest string is " << largest_string << " and it's length is " << largest_len << endl;
    
    return 0;
}
