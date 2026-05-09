class Solution {
public:
    void rotateArrToLeft(vector<int>& nums, int& n, int k) {        
        // reverse first K elements
        reverse(nums.begin(), nums.begin()+k);
        
        // reverse all remaining elements
        reverse(nums.begin()+k, nums.end());
        
        // reverse all the elements
        reverse(nums.begin(), nums.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rowCnt = grid.size(), colCnt = grid[0].size();
        int layerCnt = min(rowCnt, colCnt) / 2;
        vector<vector<int>> res(rowCnt, vector<int>(colCnt, 0));

        for(int currLayer = 0; currLayer < layerCnt; ++currLayer) {
            int minRow = 0 + currLayer, maxRow = rowCnt - 1 - currLayer;
            int minCol = 0 + currLayer, maxCol = colCnt - 1 - currLayer;

            int currLayerSize = 2*(colCnt-2*currLayer) + 2*(rowCnt-2*(currLayer+1));
            vector<int> tmpArray;

            // Push Top of Layer
            for(int i = minCol; i <= maxCol; ++i)
                tmpArray.push_back(grid[minRow][i]);

            // Push Right of Layer
            for(int i = minRow+1; i < maxRow; ++i)
                tmpArray.push_back(grid[i][maxCol]);
            
            // Push Bottom of Layer
            for(int i = maxCol; i >= minCol; --i)
                tmpArray.push_back(grid[maxRow][i]);
            
            // Push Left of Layer
            for(int i = maxRow-1; i > minRow; --i)
                tmpArray.push_back(grid[i][minCol]);
            
            rotateArrToLeft(tmpArray, currLayerSize, k % currLayerSize);

            int idx = 0;
            // Push Top of Layer
            for(int i = minCol; i <= maxCol; ++i)
                res[minRow][i] = tmpArray[idx++];

            // Push Right of Layer
            for(int i = minRow+1; i < maxRow; ++i)
                res[i][maxCol] = tmpArray[idx++];
            
            // Push Bottom of Layer
            for(int i = maxCol; i >= minCol; --i)
                res[maxRow][i] = tmpArray[idx++];
            
            // Push Left of Layer
            for(int i = maxRow-1; i > minRow; --i)
                res[i][minCol] = tmpArray[idx++];
        }

        return res;
    }
};