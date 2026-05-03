class Solution {
public:
    bool rotateString(string s, string goal) {
        string newStr = s + s;
        if(s.size() != goal.size()) {
            return false;
        }

        return newStr.find(goal) != string::npos;
    }
};