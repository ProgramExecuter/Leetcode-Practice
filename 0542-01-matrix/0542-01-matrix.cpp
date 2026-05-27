class Solution {
    struct Ele {
        int row, col, dist;
        Ele(int row, int col, int dist)
            : row(row), col(col), dist(dist) {}
    };

    vector<vector<int>> res;
    // vector<vector<bool>> vis;
    int nRow, nCol;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        nRow = mat.size();
        nCol = mat[0].size();
        res.assign(nRow, vector<int>(nCol, -1));
        // vis.assign(nRow, vector<bool>(nCol, false));
        queue<Ele> travQ;

        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    travQ.push(Ele(i, j, 0));
                    // vis[i][j] = true;
                }
            }
        }

        int rowDir[] = {-1, 0, 1, 0};
        int colDir[] = {0, +1, 0, -1};

        while(!travQ.empty()) {
            Ele curr = travQ.front();
            travQ.pop();

            for(int i = 0; i < 4; ++i) {
                int nxtRow = curr.row + rowDir[i];
                int nxtCol = curr.col + colDir[i];

                if(nxtRow < nRow  &&  nxtRow >= 0  &&  nxtCol < nCol  &&  nxtCol >= 0
                  &&  res[nxtRow][nxtCol] == -1  &&  mat[nxtRow][nxtCol] == 1) {
                    travQ.push(Ele(nxtRow, nxtCol, curr.dist+1));
                    res[nxtRow][nxtCol] = curr.dist + 1;
                    // vis[nxtRow][nxtCol] = 1;
                }
            }
        }

        return res;
    }
};