class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;
    
    TrieNode(char ch){
        //constructor
        
        //initial states
        data=ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childCount=0;
    }
};

class Trie{
    public: 
    TrieNode *root;
    Trie(char ch){
        //constructor
        root= new TrieNode(ch);
    }
    void insertUtil(string s, TrieNode* root){
        //if we have traversed all the characters of word
        if(s.length()==0){
            //mark the char as terminal
            root->isTerminal=true;
            return;
        }
        
        //search index
        int index=s[0]-'a';
        TrieNode* child;
        //if already present in trie
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            //absent
            child =new TrieNode(s[0]);
            root->childCount++;
            root->children[index]=child;
        }
        
        //recursive call
        insertUtil(s.substr(1), child);
    }
    
    void insert(string s){
        insertUtil(s, root);
    }
    
    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch=str[i];
            
            if(root->childCount==1){
                ans.push_back(ch);
                //move ahead
                int index=ch-'a';
                root= root->children[index];
            }else{
                break;
            }
            
            if(root->isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t= new Trie('\0');
    
    //insert all strings into trie
    for(int i=0; i<n; i++){
        t->insert(arr[i]);
    }
 
    string ans="";
    string first= arr[0];
    
    t->lcp(first, ans);
    return ans;
    
}


// tc:o(n*m)
// sc:o(n*m)  
