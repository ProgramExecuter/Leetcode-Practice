class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        string curr = "";
        bool prevSpace = true;
        
        for(char ch : s)
        {
            if(ch == ' ')
            {
                if(prevSpace)   continue;
                tmp.push_back(curr);
                curr = "";
                prevSpace = true;
            }
            else
            {
                curr += ch;
                prevSpace = false;
            }
        }
        if(curr.size() > 0)     tmp.push_back(curr);
        
        string res;
        
        for(int i = tmp.size()-1; i >= 0; --i)
        {
            res += tmp[i];
            if(i != 0)   res += ' ';
        }
        
        return res;
    }
};