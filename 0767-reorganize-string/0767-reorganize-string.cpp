class Solution {
public:
    string reorganizeString(string s) {
        vector<int> chCnt(26, 0);
        int idx = 0, len = s.size();
        char mxCntCh = 'a';
        
        // Find max. cnt character
        for(char ch : s) {
            if(++chCnt[ch-'a'] > chCnt[mxCntCh - 'a'])
                mxCntCh = ch;
        }
        
//         for(int i=0; i<26; ++i)     cout << char('a'+i) << "-" << chCnt[i] << "  ";
//         cout << endl;
        
        // Not possible
        if(chCnt[mxCntCh-'a'] > (len+1)/2)   return "";
        
        // Fill the max. cnt character in alternate places
        while(chCnt[mxCntCh-'a']) {
            s[idx] = mxCntCh;
            --chCnt[mxCntCh-'a'];
            idx += 2;
        }
        
        // for(int i=0; i<26; ++i)     cout << char('a'+i) << "-" << chCnt[i] << "  ";
        // cout << endl;
        
        // Fill rest of characters evenly
        for(int i = 0; i < 26; ++i) {
            while(chCnt[i]) {
                if(idx >= len)  idx = 1;
                s[idx] = char('a' + i);
                --chCnt[i];
                idx += 2;
            }
        }

        return s;
    }
};