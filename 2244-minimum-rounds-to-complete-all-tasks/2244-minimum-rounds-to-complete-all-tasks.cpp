class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Sort the tasks by difficulty
        sort(tasks.begin(), tasks.end());
        int prevTask = -1, cnt = 0, reqMinRounds = 0;
        
        for(int task : tasks) {
            // This is same level as prevTask, then '++cnt'
            if(task == prevTask)
                ++cnt;
            else {
                // Previous task level only has 1 task, so we cannot complete it
                if(cnt == 1) 
                    return -1;
                
                reqMinRounds += cnt%3 ? (cnt/3 + 1) : (cnt/3);
                cnt = 1;    prevTask = task;
            }
        }
        // Same as in loop condition ( for last tasks )
        if(cnt == 1)    return -1;
        else            reqMinRounds += cnt%3 ? (cnt/3 + 1) : (cnt/3);
        
        return reqMinRounds;
    }
};