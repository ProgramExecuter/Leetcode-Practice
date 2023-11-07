class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int mnEle = INT_MAX, cntNeg = 0;
        bool hasZero = false;
        long long sum = 0;
        
        for(auto row : matrix)
        {
            for(int curr : row)
            {
                if(curr == 0)   hasZero = true;
                mnEle = min(mnEle, abs(curr));
                
                if(curr < 0)    ++cntNeg;
                
                sum += abs(curr);
            }
        }
        
        // If the array has odd no. of -ve and doesn't have any zero to help remove it, then remove
        // smallest element from 'sum', since we'll make that -ve by doing operations many times
        if(cntNeg % 2 == 1  and  !hasZero)
            sum -= 2 * mnEle;
        
        // Else we are able to make all the elements +ve
        return sum;
    }
};