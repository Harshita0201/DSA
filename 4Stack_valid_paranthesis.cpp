class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            
            //push to stack if opening paranthesis
            //pop the TOS if closing paranthesis and match, if match found valid else not valid
            if(ch=='{' || ch=='(' || ch=='['){
                  st.push(ch);
            }else{
                //for closing paranthesis
                if(!st.empty()){
                    char top=st.top();
                    if( (ch==')' && top=='(' ) || ( ch==']' && top=='['    ) || (  ch=='}' && top=='{'   )){
                        st.pop();
                    }else{
                        return false; //no match
                    } 
                }else{
                    return false;
                }
            }
          
        }
        
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};
