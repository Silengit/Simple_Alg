class Solution {
public:
    int Add(int num1, int num2)
    {
        if (num2 == 0) return num1;
        return Add(num1 ^ num2, (num1 & num2) << 1);
    }
};