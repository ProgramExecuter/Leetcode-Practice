class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxSize;
    
    KthLargest(int k, vector<int>& nums)
    {
        maxSize = k;
        for(int num : nums)
        {
            pq.push(num);
            if(pq.size() > maxSize)     pq.pop();
        }
    }
    
    int add(int val)
    {
        pq.push(val);
        if(pq.size() > maxSize)     pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */