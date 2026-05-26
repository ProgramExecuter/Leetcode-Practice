class Solution {
    int m = 0, n = 0;
    vector<vector<int>> res;
public:
    void dfs(int sr, int sc, int& color) {
        if(res[sr][sc] == color)
            return;
        
        int prevColor = res[sr][sc];
        res[sr][sc] = color;

        // Up
        if(sr > 0  &&  prevColor == res[sr-1][sc])
            dfs(sr-1, sc, color);
        // Down
        if(sr < m-1  &&  prevColor == res[sr+1][sc])
            dfs(sr+1, sc, color);
        // Left
        if(sc > 0  &&  prevColor == res[sr][sc-1])
            dfs(sr, sc-1, color);
        // Right
        if(sc < n-1  &&  prevColor == res[sr][sc+1])
            dfs(sr, sc+1, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        res = image;
        m = image.size();
        n = image[0].size();

        dfs(sr, sc, color);

        return res;
    }
};