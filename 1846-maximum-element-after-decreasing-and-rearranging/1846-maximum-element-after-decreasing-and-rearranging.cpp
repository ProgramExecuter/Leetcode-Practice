class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        
        arr[0] = 1;
        
        for(int i = 1; i < len; ++i)
            if(arr[i] > arr[i-1])   arr[i] = arr[i-1] + 1;
        
        return arr[len-1];
    }
};