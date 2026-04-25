class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        // Calculate distance from origin(0,0)
        // Open 4-sides square in a single line
        // in anti-clockwise(my choice, reverse can also be done)
        /*
           (d,0)_________(d,d)
                |       |
                |       |
           (0,0)|_______|(d,0)
        */
        vector<long long> dist;
        for(auto point : points) {
            // Bottom Side, y == 0,  distance = x
            if(point[1] == 0)       dist.push_back(point[0]);
            // Right Side, x == side,  distance = x + y
            else if(point[0] == side)    dist.push_back(1ll*side+point[1]);
            // Top Side, y == side,  distance = side+side+(side-x)
            else if(point[1] == side)    dist.push_back(1ll*2*side + (side-point[0]));
            // Left Side, x == 0,  distance = side+side+side+(side-y)
            else if(point[0] == 0)       dist.push_back(1ll*3*side + (side-point[1]));
        }

        // Sort the distance array
        sort(dist.begin(), dist.end());

        // Find using binary search, a max distance at which
        // we can have K points
        long long res = 0, lowDist = 0, highDist = 1ll*4*side;
        while(lowDist <= highDist) {
            long long midDist = lowDist + (highDist-lowDist)/2;
            int cnt = 0;
            // Check for each starting point
            for(int i = 0; i < n; ++i) {
                long long prevDist = dist[i];
                cnt = 1;

                for(; cnt < k; ++cnt) {
                    // Find the next element which is atleast midDist from prev point
                    auto itr = lower_bound(dist.begin()+i+1, dist.end(), prevDist+midDist);
                    if(itr == dist.end())   break;

                    // This point is close to end of straight line distance
                    // which is not straight line, but a circle, whose both end
                    // starting and ending end are same point
                    if(0ll + *itr + midDist >= 1ll*4*side) {
                        long long distFromFirstPoint = dist[i] + (1ll*4*side - *itr);
                        if(distFromFirstPoint < midDist)    break;
                    }

                    prevDist = *itr;
                }

                if(cnt == k)    break;
            }
            if(cnt == k) {
                res = max(res, midDist);
                lowDist = midDist + 1;
            } else {
                highDist = midDist - 1;
            }
        }

        return res;
    }
};