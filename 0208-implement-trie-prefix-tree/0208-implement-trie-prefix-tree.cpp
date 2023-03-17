class Node {
public:
    char val;
    bool ends;
    vector<Node*> childs;
    Node(char val) {
        this->val = val;
        ends = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('1');
    }
    
    void insert(string word) {
        Node *curr = root;
        
        for(char ch : word) {
            Node* found = NULL;
            
            // Find if 'ch' is already present in child list
            for(auto child : curr->childs) {
                if(child->val == ch) {
                    found = child;
                    break;
                }
            }
            
            if(!found) {
                Node *newNode = new Node(ch);
                curr->childs.push_back(newNode);
                found = newNode;
            }
            
            curr = found;
        }
        
        curr->ends = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        
        for(char ch : word) {
            Node* found = NULL;
            
            // Find if 'ch' is present in child list
            for(auto child : curr->childs) {
                if(child->val == ch) {
                    found = child;
                    break;
                }
            }
            
            if(!found)      return false;
            
            curr = found;
        }
        
        return curr->ends;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        
        for(char ch : prefix) {
            Node* found = NULL;
            
            // Find if 'ch' is present in child list
            for(auto child : curr->childs) {
                if(child->val == ch) {
                    found = child;
                    break;
                }
            }
            
            if(!found)      return false;
            
            curr = found;
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