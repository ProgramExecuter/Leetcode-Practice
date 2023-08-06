class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        
        for(int i : candyType)  st.insert(i);
        
        return min(candyType.size() / 2 , st.size());
    }
};