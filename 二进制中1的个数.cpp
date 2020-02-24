class Solution {
public:
     int  NumberOf1(int n) {
         int ctr = 0;
         unsigned int u_n = n;
         while(u_n != 0){
             if(u_n & 1 != 0)
                 ctr++;
             u_n >>= 1;
         }
         return ctr;
     }
};