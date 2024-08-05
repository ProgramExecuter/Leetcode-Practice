class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mpIdx;
        int n = arr.size();
        
        for(int i = 0; i < n; ++i)
        {
            if(mpIdx.find(arr[i]) == mpIdx.end())
                mpIdx[arr[i]] = i;
            else
                mpIdx[arr[i]] = -1;
        }
        
        vector<pair<int, string>> tmpVect;
        for(auto curr : mpIdx)
        {
            if(curr.second != -1)
                tmpVect.push_back({curr.second, curr.first});
        }
        
        sort(tmpVect.begin(), tmpVect.end());
        
        if(tmpVect.size() < k)
            return "";
        
        return tmpVect[k-1].second;
    }
};