class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*>child;
        bool isTerm;

    TrieNode(char val){
        this->data = val;
        this->isTerm = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        isertWord(word, root);
    }
    
    bool search(string word) {
        return searchWrd(word, root);
    }
    
    bool startsWith(string prefix) {
        return findPrefix(prefix, root);
    }

    void isertWord(string word, TrieNode* root){
        if(word.length() == 0){
            root->isTerm = true;
            return;
        }

        char ch = word[0];
        TrieNode* temp;
        if(root->child.find(ch) != root->child.end()){
            temp = root->child[ch];
        }
        else{
            temp = new TrieNode(ch);
            root->child[ch] = temp;
        }
        isertWord(word.substr(1), temp);
    }

    bool searchWrd(string word, TrieNode* root){
        if(word.length() == 0){
            return root->isTerm;
        }

        char ch = word[0];
        TrieNode* temp;
        if(root->child.find(ch) != root->child.end()){
            temp = root->child[ch];
        }
        else{
            return false;
        }
        return searchWrd(word.substr(1), temp);
    }

    bool findPrefix(string word, TrieNode* root){
        if(word.length() == 0){
            return true;
        }

        char ch = word[0];
        TrieNode* temp;
        if(root->child.find(ch) != root->child.end()){
            temp = root->child[ch];
        }
        else{
            return false;
        }
        return findPrefix(word.substr(1), temp);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */