
#include<iostream>
using namespace std;

void readline(char a[], int maxlen, char delim='\n'){
    int i=0;
    char ch;
    ch = cin.get();  //reads the first character of sentence or paragraph
    while(ch!=delim){
        a[i]=ch; //store the char @i index
        i++; //update the index
        if(i==(maxlen-1)){ //if array end reached, leave last index for special character
            break;
        }
        ch = cin.get(); //read next character
    }
    a[i]='\0'; //store the special character at the endl
}

int main(){
    // char a[1000];
    // cin >> a; 
    // cout << a << endl;
    // cout << sizeof(a) << endl;
    // char b[]={'h', 'e', 'l', 'l', 'o'};
    // cout << b << endl;
    // cout << sizeof(b) << endl;
    char a[1000];
    readline(a,1000,'$');
    cout << a;
    
    //inbuilt c++ function to read sentences and paragraphs cin.getline() takes same arguments as above.
    return 0;
}
