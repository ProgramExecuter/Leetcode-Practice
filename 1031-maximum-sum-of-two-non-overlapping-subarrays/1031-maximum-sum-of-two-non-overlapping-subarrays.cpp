class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int len = nums.size();
        vector<int> leftFirst(len,0), leftSecond(len,0), rightFirst(len,0), rightSecond(len,0);
        
        int sum = 0, mx = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            
            if(i >= firstLen-1)
            {
                if(i >= firstLen)
                    sum -= nums[i-firstLen];
                mx = max(mx, sum);
                leftFirst[i] = sum;
            }
        }
        
        sum = 0, mx = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            
            if(i >= secondLen-1)
            {
                if(i >= secondLen)
                    sum -= nums[i-secondLen];
                mx = max(mx, sum);
                leftSecond[i] = mx;
            }
        }
        
        sum = 0, mx = 0;
        for(int i = len-1; i >= 0; --i)
        {
            sum += nums[i];
            
            if(i <= len-firstLen)
            {
                if(i < len-firstLen)
                    sum -= nums[i+firstLen];
                mx = max(mx, sum);
                rightFirst[i] = mx;
            }
        }
        
        sum = 0, mx = 0;
        for(int i = len-1; i >= 0; --i)
        {
            sum += nums[i];
            
            if(i <= len-secondLen)
            {
                if(i < len-secondLen)
                    sum -= nums[i+secondLen];
                mx = max(mx, sum);
                rightSecond[i] = mx;
            }
        }
        
        for(int i = 0; i < len; ++i)
            cout << leftFirst[i] << " " << leftSecond[i] << " " << rightFirst[i] << " " << rightSecond[i] << endl;
        cout << endl << endl;
        
        int res = 0;
        for(int i = 1; i < len; ++i)
        {
            // Firstlen first, Secondlen second
            res = max(res, leftFirst[i-1] + rightSecond[i]);
            
            // Secondlen first, Firstlen second
            res = max(res, leftSecond[i-1] + rightFirst[i]);
        }
        
        return res;
    }
};