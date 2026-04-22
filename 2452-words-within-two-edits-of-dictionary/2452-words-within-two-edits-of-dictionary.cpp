class Solution {
public:
    int charCnt = 26;
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int lenDict = dictionary.size(), lenQueries = queries.size();
        vector<string> res;

        for(auto query : queries) {
            for(auto dict : dictionary) {
                int diff = 0;
                for(int i = 0; i < query.size(); ++i)   {
                    if(query[i] != dict[i])     ++diff;
                }
                if(diff <= 2) {
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};