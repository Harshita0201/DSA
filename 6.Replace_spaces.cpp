// The first line contains a single integer ‘T’ representing the number of test cases. 
// The first line of each test case will contain a single string 'STR' consisting of one or more words. 
  
  
// For each test case, return the modified string after replacing all the spaces between words with “@40”.
// Print the output of each test case in a separate line.
  
// input:  
// 2
// Coding Ninjas Is A Coding Platform
// Hello World  
// output:
// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World

string replaceSpaces(string &str){
	// Write your code here.
    string temp="";
    
    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}


//less space:

for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            str= str.substr(0,i)+"@40"+str.substr(i+1,str.length());
        }
}
