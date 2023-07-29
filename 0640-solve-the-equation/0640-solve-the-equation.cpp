class Solution {
public:
    string solveEquation(string equation) {
        int coefLeft = 0, valueLeft = 0;
        int coefRight = 0, valueRight = 0;
        
        bool isRight = false;
        
        int currVal = 0, sign = 1;
        
        for(int i = 0; i < equation.size(); ++i) {
            char ch = equation[i];
            
            if(ch >= '0' and ch <= '9') {
                currVal = currVal*10 + (ch-'0');
            }
            else if(ch == 'x') {
                if(currVal == 0) {
                    if(i > 0  and  equation[i-1] == '0')
                        currVal = 0;
                    else
                        currVal = 1;
                }
                
                if(isRight) coefRight += currVal * sign;
                else        coefLeft += currVal * sign;
                
                currVal = 0;    sign = 1;
            }
            else if(ch == '+') {
                if(isRight) valueRight += currVal * sign;
                else        valueLeft += currVal * sign;
                
                currVal = 0;    sign = 1;
            }
            else if(ch == '-') {
                if(isRight) valueRight += currVal * sign;
                else        valueLeft += currVal * sign;
                
                currVal = 0;    sign = -1;
            }
            else {
                valueLeft += currVal * sign;
                currVal = 0;    sign = 1;
                
                isRight = true;
            }
            // cout << "[" << ch << "] " << coefLeft << " " << valueLeft << " - " << coefRight << " " << valueRight << " - " << sign << " " << currVal << endl;
        }
        valueRight += currVal * sign;
        
        // cout << coefLeft << " " << valueLeft << " - " << coefRight << " " << valueRight << endl;
        
        if(coefLeft == coefRight) {
            if(valueLeft == valueRight) return "Infinite solutions";
            else                        return "No solution";
        }
        else {
            int res;
            if(coefLeft > coefRight)
                res = (valueRight-valueLeft) / (coefLeft-coefRight);
            else
                res = (valueLeft-valueRight) / (coefRight-coefLeft);
            
            return "x="+to_string(res);
        }
    }
};