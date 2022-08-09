https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
class TrieNode{
    public: 
    char data;
    TrieNode *children[26];
    bool isTerminal;
    
    TrieNode(char ch){//constructor
        //initial states->
        data=ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
    
};

class Trie{
    public:
    TrieNode *root;
    Trie(){ //constructor
        root= new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        //if we have inserted all the characters of the word 
        if(word.length()==0){ //end the string, mark TrieNode as terminal 
            root->isTerminal=true;
            return;
        }
        
        //finding indedx, assumption word will be in CAPS
        int index= word[0]-'a';
        
        TrieNode *child;
        
        //present
        if(root->children[index]!=NULL){
            child=root->children[index]; //mark that character as child node of root 
        }else{
            //absent
            child= new TrieNode(word[0]); //create new child node
            root->children[index]=child; //insert child node as children of root
        }
        
        //recursive call for rest of the characters of word
        insertUtil(child, word.substr(1));
        
    }
    
    void insert(string word){
        insertUtil(root, word);
    }
    void printSuggestions(TrieNode *curr, vector<string>&temp, string prefix){
        if(curr->isTerminal){//traversed all the characters of string
            temp.push_back(prefix);
        }
        
        for(char ch='a'; ch<='z'; ch++){
            TrieNode *next =curr->children[ch-'a'];
            if(next!=NULL){//if next exists
                prefix.push_back(ch);
                //recursicve call
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSugesstions(string str){
        TrieNode *prev=root;
        vector<vector<string>> output;
        string prefix="";
        
        for(int i=0; i<str.length(); i++){
            char lastChar=str[i];
            
            prefix.push_back(lastChar);
            
            //check for lastChar in parent node or children of prev node
            TrieNode *curr =prev->children[lastChar-'a'];
            
            //if not found
            if(curr==NULL){
                break;
            }
            
            //if found, print all suggestions
            vector<string> temp; //all suggestions will be in temp
            printSuggestions(curr, temp, prefix);
            
            //push all suggestions into output
            output.push_back(temp);
            temp.clear();
            //move prev ahead
            prev=curr;
        }
        return output;
    }
    
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie *t=new Trie();
    
    // insert all contacts into trie
    for(int i=0; i<contactList.size(); i++){
        t->insert(contactList[i]);
    }
    
    //return ans
    return t->getSugesstions(queryStr);
}
// TC: o(n*(m^2))
  
