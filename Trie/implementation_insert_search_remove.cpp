#include<bits/stdc++.h>
using namespace std;
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

class Trie{
    public:
    TrieNode *root;
    Trie(){
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
        int index= word[0]-'A';
        
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
    
    bool searchUtil(TrieNode* root, string word){
        //base case, travered all characters of words and reached the end
        if(word.length()==0){
            return root->isTerminal; //if it is the end, then whole word is present
        }
        
        //find index
        int index = word[0]-'A';
        
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
    bool search(string word){
        return searchUtil(root, word);
    }
    
    bool isEmpty(TrieNode *root){
        //returns false if root has children, else true
        for(int i=0; i<26; i++){
            if(root->children[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    
    void removeUtil(TrieNode*root, string word){
        if(word.length()==0){
            root->isTerminal=false; //if it is the end, then whole word is present, mark it's terminal as false
            return;
        }
        
        //search word
        int index=word[0]-'A';
        TrieNode *child;
        
        if(root->children[index]!=NULL){
            //present
            child=root->children[index];
            // If given is not prefix of any other word
            if (isEmpty(root)) {
                delete (root);
                root = NULL;
            }
        }else{
            //absent
            cout << "not present, nothing to delete " << endl;
        }
        
        //recursive calls for further index 
          return removeUtil(child, word.substr(1));
    }
    
    void remove_word(string word){
        return removeUtil(root, word);
    }
    
    
};

int main(){
    Trie t;
    t.insert("ABCD");
    cout << "is present or not?" << t.search("ABCD") << endl;
    cout << "is present or not?" << t.search("ABCDE") << endl;
    t.remove_word("ABCD");
    cout << "After removal" << endl;
    cout << "is present or not?" << t.search("ABCD") << endl;
    //cout << "is Trie empty?" << t.isEmpty() << endl;
    return 0;
}

//tc of every solution : o(l) l is lenght of word
//sc The space complexity of creating a trie is O(alphabet_size * average key length * N) where N is th number of words in the trie.
