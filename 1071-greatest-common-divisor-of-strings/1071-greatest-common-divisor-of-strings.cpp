class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        
        string res = "";
        
        for(int i = len1; i >= 1; --i) {
            // If pattern's length can't divide strings without remainder, so no result, continue 
            if(len1 % i != 0)   continue;
            if(len2 % i != 0)   continue;
            
            // Current pattern to check
            string patt = str1.substr(0, i);
            
            // The string 'str2' is smaller than the pattern, thus impossible
            if(len2 < i)    continue;
            
            bool isValid1 = true, isValid2 = true;
            
            // Check if this pattern can be followed in 'str1'
            for(int j = 0; j < len1; j += i) {
                string currSub = str1.substr(j, i);
                if(currSub.compare(patt) != 0)
                    isValid1 = false;
            }
            
            // Check if this pattern can be followed in 'str2'
            for(int j = 0; j < len2; j += i) {
                string currSub = str2.substr(j, i);
                if(currSub.compare(patt) != 0)
                    isValid2 = false;
            }
            
            // Is a valid pattern for both strings
            if(isValid1  and  isValid2)
                return patt;
        }
        
        return res;
    }
};