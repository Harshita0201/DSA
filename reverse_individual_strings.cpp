// Given a string str, we need to print reverse of individual words.
// Examples: 
 

// Input : Hello World
// Output : olleH dlroW
 
// Input :  Geeks for Geeks
// Output : skeeG rof skeeG



#include<iostream>
#include<stack>
using namespace std;
void reverse_inidivdual_words(string s){
    stack <char>st;
    
    for(int i=0; i<s.length(); ++i){
        if(s!=" "){
            st.push(s[i]);
        }else{
            while(st.empty()!=false){
            cout << st.top();
            st.pop();
         }
        }
        cout << " ";
    }
    
    // Since there may not be space after
    // last word.
    
    while (st.empty() == false) {
        cout << st.top();
        st.pop();
    }
}



int main(){
    //string str="geeks for geeks";
    string str;
    getline(cin,str);
    
    reverse_inidivdual_words(str);
    return 0;
}
