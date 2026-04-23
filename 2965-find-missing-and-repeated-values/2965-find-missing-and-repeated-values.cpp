class Solution {
public:
    vector<int> mathSolution(vector<vector<int>>& grid) {
        int n = grid.size();

        // missing - repeating
        long long m_r = (1ll * (n*n) * (n*n + 1)) / 2;
        for(auto arr : grid) {
            for(auto num : arr)     m_r -= num;
        }

        // missing^2 - repeating^2
        long long m2_r2 = (1ll * (n*n) * (n*n + 1) * (2*n*n + 1)) / 6;
        for(auto arr : grid) {
            for(auto num : arr)     m2_r2 -= num*num;
        }

        // m2-r2 / m-r => m+r
        long long mr = m2_r2 / m_r;

        // m-r + m+r => 2m
        int missingNum = (m_r + mr) / 2;
        // m+r - (m-r) => 2r
        int repeatingNum = (mr - m_r) / 2;

        return {repeatingNum, missingNum};
    }
    vector<int> xorSolution(vector<vector<int>>& grid) {
        int n = grid.size();
        int xorFM = 0;

        // Do xor of both series
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                xorFM ^= grid[i][j];
                xorFM ^= (i*n + j + 1);
            }
        }

        // Find any/first bit which is set
        int idx = 0;
        while(1) {
            int num = 1 << idx;
            if(xorFM & num)   break;
            ++idx;
        }

        int xor0 = 0, xor1 = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int num1 = grid[i][j];
                int num2 = i*n + j + 1;
                int toXor = 1 << idx;

                if(num1 & toXor)    xor1 ^= num1;
                else                xor0 ^= num1;

                if(num2 & toXor)    xor1 ^= num2;
                else                xor0 ^= num2;
            }
        }

        bool found = any_of(grid.begin(), grid.end(), [&](const vector<int>& row) {
            return find(row.begin(), row.end(), xor0) != row.end();
        });

        if(found)
            return {xor0, xor1};
        else
            return {xor1, xor0};
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // return mathSolution(grid);
        return xorSolution(grid);
    }
};