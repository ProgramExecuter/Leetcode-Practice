class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        
        for(int bill : bills)
        {
            int changeToGive = bill - 5;
            
            if(bill == 5)           ++fives;
            else if(bill == 10)     ++tens;
            else                    ++twenties;
            
            int given20 = min(changeToGive / 20, twenties);
            twenties -= given20;
            changeToGive -= given20 * 20;
            
            int given10 = min(changeToGive / 10, tens);
            tens -= given10;
            changeToGive -= given10 * 10;
            
            int given5 = min(changeToGive / 5, fives);
            fives -= given5;
            changeToGive -= given5 * 5;
            
            if(changeToGive > 0)
                return false;
        }
        
        return true;
    }
};