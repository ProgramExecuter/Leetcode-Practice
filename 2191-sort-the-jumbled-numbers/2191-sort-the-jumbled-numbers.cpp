class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        // New Num => prevIndex, prevNum
        multimap<int, pair<int, int>> newArray;
        int len = nums.size();
        
        for(int i = 0; i < len; ++i)
        {
            int newNum = 0, tmpNum = nums[i];
            
            if(tmpNum == 0)
            {
                newArray.insert({mapping[0], {i, nums[i]}});
                continue;
            }
            
            stack<int> st;
            while(tmpNum > 0)
            {
                st.push(mapping[tmpNum % 10]);
                tmpNum /= 10;
            }
            while(!st.empty())
            {
                newNum = (newNum * 10) + st.top();
                st.pop();
            }
            cout << newNum << " ";
            
            newArray.insert({newNum, {i, nums[i]}});
        }
        cout << endl;
        
        vector<int> res;
        for(auto i : newArray)
            res.push_back(i.second.second);
        
        return res;
    }
};