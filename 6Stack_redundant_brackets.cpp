// Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
// Note :
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.
// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
// While (a + (b*c)) does not have any pair of redundant brackets. 







#include<stack>
bool findRedundantBrackets(string &s)
{
	stack <char> st;
    // Write your code here.
	for(int i=0; i<s.length(); i++){
		char ch=s[i];
		//if character is opening bracket or some operator push to stack
		if(ch=='(' || ch=='+' || ch=='*' || ch=='-' || ch=='/'){
			st.push(ch);
		}else{
			//either closing bracket or lower case character
			if(ch==')'){
				bool isRedundant=true;
				while(st.top()!='('){ // do untill you get one opening bracket 
					char tos=st.top();
				    //if TOS is operator
				    if(tos=='+' || tos=='*' || tos=='-' || tos=='/'){
				    	//mark isRedundant as fasle
						isRedundant=false;
				    }
					st.pop();
				}
				if(isRedundant==true){
					return true;
				}
				st.pop();
					
			}
				
		}
	}
	
	return false;
}
