class Solution {
public:
    vector<vector<char>> rotate90Deg(vector<vector<char>>& vec, int& m, int& n) {
        vector<vector<char>> res;

        for(int col = 0; col < n; col++) {
            vector<char> tmp;
            for(int row = m-1; row >= 0; --row)
                tmp.push_back(vec[row][col]);
            res.push_back(tmp);
        }

        return res;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));
        
        // Go per row
        for(int i = 0; i < m; ++i) {
            int cntStones = 0;
            for(int j = 0; j < n; ++j) {
                cout << "Heloo" << endl;
                if(boxGrid[i][j] == '#') {
                    cout << "Heloo1" << endl;
                    ++cntStones;
                } else if(boxGrid[i][j] == '*') {
                    cout << "Heloo2" << endl;
                    // Place Stones
                    for(int k = j-1; cntStones > 0; --k, --cntStones)
                        res[i][k] = '#';
                    cout << cntStones << endl;
                    res[i][j] = '*';
                }
            }
            for(int k = n-1; cntStones > 0; --k, --cntStones)
                res[i][k] = '#';
        }
        
        return rotate90Deg(res, m, n);
    }
};