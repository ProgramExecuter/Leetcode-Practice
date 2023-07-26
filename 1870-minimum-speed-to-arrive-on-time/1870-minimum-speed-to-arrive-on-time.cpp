class Solution {
public:
    double util(vector<int>& dist, int speed) {
        double reqHr = 0.0;
        
        for(int i = 0; i < dist.size(); ++i) {
            if(i == dist.size()-1)
                reqHr += (1.0*dist[i]) / speed;
            else
                reqHr += floor((1.0*dist[i]) / speed + 0.99999999);
        }
        
        return reqHr;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int len = dist.size();
        
        if(hour <= len-1)  return -1;
        
        int low = 1, high = 1e8;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            double reqHr = util(dist, mid);
            
            cout << low << " " << high << " -> " << reqHr << endl;
            
            if(reqHr <= hour)
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};