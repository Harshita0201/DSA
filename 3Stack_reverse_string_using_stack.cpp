// You are given a string S, the task is to reverse the string using stack.

 

// Example 1:


// Input: S="GeeksforGeeks"
// Output: skeeGrofskeeG

char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    
    for(int i=0; i<len; i++){
        char ch=S[i];
        st.push(ch);
    }
    
    //char *str="";
    int i=0;
    while(!st.empty()){
        S[i++]=st.top(); //get top
        st.pop(); //remove top
    }
    return S;
}
