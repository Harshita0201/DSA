// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, 
// consider alphabets and numbers only and ignore the symbols and whitespaces.
  
 //Let S = “c1 O$d@eeD o1c”.
//If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase,
//we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.


bool ValidChar(char ch){
    if((ch<='Z' && ch>='A') ||(ch<='z' && ch>='a')||(ch>='0' && ch<='9'))
        return true;
    return false;
}

char tolowercase(char ch){
    if(ch >='A' && ch<='Z'){
        return ch-'A'+'a';
    }
    return ch;
}

bool checkPalindrome(string s)
{
    // Write your code here.
    int i = 0;
    int j = s.length()-1;
    
    while(i<j){
        if(!ValidChar(s[i])){
            i++;
            continue;
        }
        if(!ValidChar(s[j])){
            j--;
            continue;
        }
        if(tolowercase(s[i]) != tolowercase(s[j])) return false;
        i++;
        j--;
    }
    return true;
    
}
