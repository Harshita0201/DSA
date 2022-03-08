// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, 
// consider alphabets and numbers only and ignore the symbols and whitespaces.
  
 //Let S = “c1 O$d@eeD o1c”.
//If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase,
//we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.


char toLower(char s){
    //char temp;
    if(s>='a' && s<='z'){ //lower case
        return s;
    }else{ //upper case
        char temp=s-'A'+'a'; //upper to lower 
        return temp;
    }
    
}
bool checkPalindrome(string s)
{
    // Write your code here.
    int str=0;
    int e=s.size()-1;
    
    while(str<e){
         while(!(s[str]>='a' && s[str]<='z' || s[str]>='A' && s[str]<='Z' || s[str]>='0' && s[str]<='9')){
            str++;
        }
        while(!(s[e]>='a' && s[e]<='z' || s[e]>='A' && s[e]<='Z' || s[e]>='0' && s[e]<='9')){
            e--;
        }
        if(toLower(s[str])!=toLower(s[e])){
           
            return 0;
        }
        else{
            str++;
            e--;
        }
    }
    return 1;
}
