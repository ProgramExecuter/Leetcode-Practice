class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCnt = 0;
        for(char ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
        }
        return false;
    }
};