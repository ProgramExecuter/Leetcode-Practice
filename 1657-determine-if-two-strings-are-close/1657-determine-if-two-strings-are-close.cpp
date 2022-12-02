class Solution {
public:
    bool closeStrings(string given, string target) {
        // Saves cnt of characters in target,   'a' = 0
        vector<int> charCntTar(26, 0), charCntGiv(26, 0);
        
        // Keeps all counts needed, for 'given' to become 'target'
        map<int, int> mp;
        set<char> st;
        
        // Count all characters in both strings
        for(char ch : given) {
            ++charCntGiv[ch-'a'];
            st.insert(ch);
        }
        
        for(char ch : target) {
            // A char found that is not in one string, but is there in another
            if(st.find(ch) == st.end())
                return false;
            
            ++charCntTar[ch-'a'];
        }
        
        // Save the count of (count of character) in a map
        for(int cnt : charCntGiv)
            ++mp[cnt];
        
        // Check if there is a count available for all letters in 'given'
        // string for it to become 'target'
        for(int cnt : charCntTar) {
            if(mp.find(cnt) == mp.end()  or  mp[cnt] == 0)
                return false;
            else
                --mp[cnt];
        }
        
        return true;
    }
};