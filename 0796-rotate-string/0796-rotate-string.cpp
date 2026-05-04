class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);

        int len = 0, i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
        return lps;
    }
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string text = s + s;
        vector<int> lps = buildLPS(goal);

        int i = 0; // text pointer
        int j = 0; // pattern pointer

        while (i < text.length()) {
            if (text[i] == goal[j]) {
                i++;
                j++;
            }

            if (j == goal.length()) {
                return true; // found match
            }
            else if (i < text.length() && text[i] != goal[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};