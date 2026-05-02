class Solution {
public:
    bool isChangedAfterRotation(int num) {
        bool isChanged = false;
        while(num > 0) {
            int digit = num % 10;
            
            switch(digit) {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                case 5:
                case 6:
                case 9:
                    isChanged = true;
                    break;
                default:
                    return false;
            }

            num /= 10;
        }

        return isChanged;
    }
    int rotatedDigits(int n) {
        int cnt = 0;

        for(int i = 1; i <= n; ++i) {
            if(isChangedAfterRotation(i)) {
                cout << i << endl; 
                ++cnt;
            }
        }

        return cnt;
    }
};