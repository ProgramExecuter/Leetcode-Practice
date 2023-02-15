class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        
        for(int i = num.size()-1; i >= 0; --i) {
            int curr = carry + num[i] + k % 10;
            num[i] = curr % 10;
            carry = curr / 10;
            k /= 10;
        }
        
        // If we have carry remaining then add a new digit at the start
        while(k + carry > 0) {
            int curr = carry + k % 10;
            num.insert(num.begin(), curr % 10);
            carry = curr / 10;
            k /= 10;
        }
        
        return num;    
    }
};