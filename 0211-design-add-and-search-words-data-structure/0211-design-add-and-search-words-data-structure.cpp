class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*>child;
        bool isTerm;

    TrieNode(char data){
        this->data = data;
        this->isTerm = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('-');
    }
    
    void addWord(string word) {
        insertWord(root, word);
    }
    
    bool search(string word) {
        return searchWrd(root, word);
    }

    void insertWord(TrieNode* root, string word){
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
        insertWord(temp, word.substr(1));
    }

    bool searchWrd(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerm;
        }

        char ch = word[0];
        TrieNode* temp;

        if(ch == '.'){
            for(auto &p : root->child){
                if(searchWrd(p.second, word.substr(1))){
                    return true;
                }
            }
            return false;
        }else{
            if(root->child.find(ch) == root->child.end()){
                return false;
            }
            return searchWrd(root->child[ch], word.substr(1));
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */