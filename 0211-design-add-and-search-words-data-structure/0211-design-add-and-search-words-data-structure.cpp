struct trie {
    trie *child[26];
    bool end;
};
class WordDictionary {
    trie *root;
public:
    WordDictionary() {
        root = new trie();
    }
    
    void addWord(string word) {
        trie *n = root;
        
        for(auto c : word) {
            if(n->child[c-'a'] == NULL)
                n->child[c-'a'] = new trie();
            n = n->child[c-'a'];
        }
        
        n->end = true;
    }
    bool dfs(int i, string s, trie *n) {
        if(i == s.size())   return n->end;
        
        if(s[i] == '.') {
            for(int ind = 0; ind < 26; ind++)
                if(n->child[ind]  &&  dfs(i+1, s, n->child[ind]))
                    return true;
        }
        else if(n->child[s[i]-'a']  &&  dfs(i+1, s, n->child[s[i]-'a']))
            return true;
        
        return false;
    }
    bool search(string word) {
        return dfs(0, word, root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */