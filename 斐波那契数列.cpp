class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        int a = 0,b = 1,res;
        for(int i=2; i<=n; i++)
        {
            res=a+b;
            a=b;
            b=res;
        }
        return res;
    }
};