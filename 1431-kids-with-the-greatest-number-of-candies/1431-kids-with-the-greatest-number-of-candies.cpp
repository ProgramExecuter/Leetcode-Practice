class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxNoCandies = 0;
        
        for(int tmp : candies)
            mxNoCandies = max(mxNoCandies, tmp);
        
        vector<bool> res;
        for(int tmp : candies)
        {
            if(tmp + extraCandies >= mxNoCandies)
                res.push_back(true);
            else
                res.push_back(false);
        }
        
        return res;
    }
};