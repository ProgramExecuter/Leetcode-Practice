class Solution {
public:
    int addDigits(int num) {
        while(num) {
            if(num/10 == 0)
                break;
            
            int sum = 0, tmp = num;
            while(tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            
            num = sum;
        }
        
        return num;
    }
};