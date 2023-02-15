class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        vector<int> res;
        
        for(int i = num.size()-1; i >= 0  or  carry + k; --i) {
            int curr = carry + k % 10;
            if(i >= 0)  curr += num[i];
            
            res.push_back(curr % 10);
            
            carry = curr / 10;
            k /= 10;
        }
        
        // Reverse the array
        reverse(res.begin(), res.end());
        
        return res;    
    }
};