class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);
        
        // Minimum time required to reach fx, fy
        int mnTime = 0;
        mnTime += min(dx, dy);      // Reached using diagonal neighbours
        mnTime += abs(dx - dy);     // remaining x-axis OR y-axis from target 
        
        if(t < mnTime)
            return false;
        if(sx == fx and sy == fy and t-mnTime == 1)
            return false;
        return true;
    }
};