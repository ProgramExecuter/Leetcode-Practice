class Solution
{
public:
    bool checkDivisor(string &matching, string &s1, string &s2)
    {
        int len = matching.length();
        int len1 = s1.length(), len2 = s2.length();
        int idx1 = 0, idx2 = 0;
        
        while(idx1+len <= len1  and  s1.substr(idx1, len) == matching)
            idx1 += len;
        
        while(idx2+len <= len2  and  s2.substr(idx2, len) == matching)
            idx2 += len;
        
        return idx1 == len1  and  idx2 == len2;
    }
    string gcdOfStrings(string str1, string str2)
    {
        int len1 = str1.length(), len2 = str2.length();
        int idx1 = 0, idx2 = 0;
        string matching = "", foundMatch = "";
        
        while(idx1 < len1  and  idx2 < len2)
        {
            if(str1[idx1] == str2[idx2])
            {
                matching += str1[idx1];
                bool isDivisor = checkDivisor(matching, str1, str2);
                                
                ++idx1;
                ++idx2;
                
                if(!isDivisor)      continue;
                
                foundMatch = matching;
            }
            else
            {
                break;
            }
        }
        
        return foundMatch;
    }
};