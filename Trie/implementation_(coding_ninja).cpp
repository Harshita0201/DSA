/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode{
    public:
    char data;
    TrieNode * children[26];
    bool isTerminal;
    
    TrieNode(char ch){// constructor
        //initial state of a new TrieNode ndoe
        data=ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};


class Trie {

public:
   
    TrieNode *root;
  
    /** Initialize your data structure here. */
    Trie() {
        //constructor
        root=new TrieNode('\0');
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
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        return insertUtil(root, word);
    }
    
    
    bool searchUtil(TrieNode* root, string word){
        //base case, travered all characters of words and reached the end
        if(word.length()==0){
            return root->isTerminal; //if it is the end, then whole word is present
        }
        
        //find index
        int index = word[0]-'a';
        
        TrieNode *child;
        
        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            //absent
            return false;
        }
        
        //recursive calls for other characters of word
        return searchUtil(child, word.substr(1));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool prefixUtil(TrieNode* root, string word){
        //base case, travered all characters of words and reached the end
        if(word.length()==0){
            return true; //if it is the end, then given prefix is present
        }
        
        //find index
        int index = word[0]-'a';
        
        TrieNode *child;
        
        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            //absent
            return false;
        }
        
        //recursive calls for other characters of word
        return prefixUtil(child, word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         return prefixUtil(root, prefix);
    }
};
