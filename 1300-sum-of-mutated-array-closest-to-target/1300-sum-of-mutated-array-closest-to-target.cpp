class Solution {
public:
    int diff(int mid, vector<int>& arr, int target)
    {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
            sum += min(mid, arr[i]);
        
        return abs(target - sum);
    }
    int findBestValue(vector<int>& arr, int target)
    {
        int len = arr.size();
        int left = 0;
        int right = target;
        
        while(left < right)
        {
            int mid = left + (right - left)/2;
            
            if(diff(mid, arr, target) <= diff(mid + 1, arr, target))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};