class Solution {
public:
    bool possibleToShip(vector<int>& weights, int capacity, int days)
    {
        int currWeight = 0;
        --days;
        
        for(int i = 0; i < weights.size(); ++i)
        {
            if(weights[i] > capacity)   return false;
            if(currWeight + weights[i] > capacity)
            {
                --days;
                currWeight = 0;
            }
            
            currWeight += weights[i];
        }
        
        return days >= 0;
    }
    int shipWithinDays(vector<int>& weights, int days)
    {
        int sum = 0;
        for(int x : weights)    sum += x;
        
        int left = 1, right = sum;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(possibleToShip(weights, mid, days))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};