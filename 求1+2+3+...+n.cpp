class Solution {
public:
    int Sum_Solution(int n) {
        int res = 0;
        n && (res = n + Sum_Solution(n-1));
        return res;
    }
};