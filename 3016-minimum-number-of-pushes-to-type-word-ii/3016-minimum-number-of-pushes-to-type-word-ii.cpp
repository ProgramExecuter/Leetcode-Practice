class Solution {
public:
    int minimumPushes(string word)
    {
        vector<int> charCnt(26, 0);
        
        for(char ch : word)
            ++charCnt[ch - 'a'];
        
        sort(charCnt.begin(), charCnt.end(), greater<int>());
        
        int idx = 1, noButtonPush = 1, noButtonsToPush = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(idx % 9 == 0)
            {
                idx = 1;
                ++noButtonPush;
            }
            
            noButtonsToPush += (noButtonPush * charCnt[i]);
            ++idx;
        }
        
        return noButtonsToPush;
    }
};