class MyHashMap
{
public:
    vector<vector<pair<int, int>>> mp;
    int len = 10000;        // Max calls(so max. unique keys)
    
    MyHashMap()
    {
        mp.resize(len);
    }
    
    void put(int key, int value)
    {
        for(auto &itr : mp[key % len])
        {
            if(itr.first == key)
            {
                itr.second = value;
                return;
            }
        }
        
        mp[key % len].push_back({key, value});
    }
    
    int get(int key)
    {
        for(auto itr : mp[key % len])
        {
            if(itr.first == key)
                return itr.second;
        }
        
        return -1;
    }
    
    void remove(int key)
    {
        for(int i = 0; i < mp[key % len].size(); ++i)
        {
            if(mp[key%len][i].first == key)
            {
                mp[key%len].erase(mp[key%len].begin() + i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */