class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        vector<double> time;
        for(int i = 0; i < dist.size(); ++i)        time.push_back(1.0 * dist[i] / speed[i]);
        sort(time.begin(), time.end());
        
        for(double curr : time)
            cout << curr << " ";
        cout << endl;
        
        int nEliminated = 0, currTime = 0;
        
        for(double curr : time)
        {
            if(currTime < curr)
                ++nEliminated;
            else
                break;
            ++currTime;
        }
        
        return nEliminated;
    }
};