class Solution {
public:
    int numberOfSpecialChars(string word) {
        // last index of lowercase letter
        // first index of uppercase letter
        vector<pair<int, int>> idxChar(26, {-1,-1});
        int len = word.size(), cnt = 0;

        for(int i = 0; i < len; ++i) {
            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {
                idxChar[ch-'a'].first = i;
            } else {
                if(idxChar[ch-'A'].second != -1)    continue;
                idxChar[ch-'A'].second = i;
            }
        }

        for(auto curr : idxChar) {
            if(curr.first == -1 || curr.second == -1)
                continue;
            
            if(curr.first < curr.second)    ++cnt;
        }

        return cnt;
    }
};