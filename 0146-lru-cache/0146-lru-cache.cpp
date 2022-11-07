class DLL {
public:
    int key, val;
    DLL *next = NULL, *prev = NULL;
    
    DLL(int key, int val) {
        this->key = key;
        this->val = val;
    }
};
class LRUCache {
    int cap, noOfEle;
    DLL *front, *back;
    map<int, DLL*> mp;
public:
    void removeFromBack() {
        DLL* tmp = back->prev;
        back->prev = tmp->prev;
        tmp->prev->next = back;
    }
    void insertAtFront(DLL* newNode) {
        newNode->next = front->next;
        newNode->prev = front;
        front->next->prev = newNode;
        front->next = newNode;
    }
    void removeFromPlace(DLL* tmp) {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    LRUCache(int capacity) {
        cap = capacity;
        noOfEle = 0;
        
        // Make relation  front -- back
        front = new DLL(0, 0);
        back  = new DLL(0, 0);
        
        front->next = back;
        back->prev = front;
    }
    int get(int key) {
        // Key not found
        if(mp.find(key) == mp.end())
            return -1;
        
        // Found the key
        DLL* tmp = mp[key];
        
        // Remove it from its place, and place it to front
        removeFromPlace(tmp);
        insertAtFront(tmp);
        
        return tmp->val;
    }
    void put(int key, int value) {
        // Create a new node
        DLL* newNode;
        
        if(mp.find(key) == mp.end()) {
            newNode = new DLL(key, value);
            // Increment the number Of elements
            ++noOfEle;
        }
        else {
            newNode = mp[key];
            newNode->val = value;
            
            removeFromPlace(newNode);
        }
        mp[key] = newNode;
            
        insertAtFront(newNode);
        
        // If elements > than capacity, delete from 'back'
        if(noOfEle > cap) {
            DLL* del = back->prev;
            mp.erase(del->key);
            
            removeFromBack();
            
            --noOfEle;
            delete del;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */