class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
            return true;
        if(ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s)
    {
        int len = s.size();
        int idxSt = 0, idxEn = len-1;
        
        while(idxSt < idxEn)
        {
            while(idxSt < len  and  !isVowel(s[idxSt]))
                ++idxSt;
            while(idxEn >= 0  and  !isVowel(s[idxEn]))
                --idxEn;
            
            if(idxSt >= idxEn)
                break;
            swap(s[idxSt], s[idxEn]);
            ++idxSt;    --idxEn;
        }
        
        return s;
    }
};