class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        if(exponent < 0){
            exponent = -exponent;
            base = 1/base;
        }
        for(int i = 0; i < exponent; i++)
            result *= base;
        return result;
    }
};