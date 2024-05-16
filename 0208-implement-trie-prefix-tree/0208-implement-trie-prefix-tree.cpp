struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = nullptr;
        isEnd = false;
    }
};


class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = nullptr;
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char x : word){
            int index = x - 'a';
            if(curr->child[index] == nullptr)
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char x : word){
            int index = x - 'a';
            if(curr->child[index] == nullptr)
                return false;
            curr = curr->child[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char x : prefix){
            int index = x - 'a';
            if(curr->child[index] == nullptr)
                return false;
            curr = curr->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */