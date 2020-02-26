class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0)
            return -1;
        bool a[n];
        for(int i = 0; i < n; i++)
            a[i] = false;
        int j = -1;
        for(int i = 1; i < n; i++){
            int left = m;
            while(left > 0){
                if(j == n - 1)
                    j = 0;
                else j++;
                if(a[j] == false)
                    left --;
            }
            a[j] = true;
        }
        for(int i = 0; i < n; i++)
            if(a[i] == false)
                return i;
    }
};