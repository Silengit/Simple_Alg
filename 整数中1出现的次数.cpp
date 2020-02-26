class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum = 0, i = 0, n2 = n;
        while(n2 > 0){
            if(n2 % 10 == 1 && i != 0)
                sum += (n % int(pow(10, i)) + 1 + n2 / 10 * pow(10, i++));
            else
                sum += (n2 + 9) / 10 * pow(10, i++);
            n2 /= 10;
        }
        return sum;
    }
};