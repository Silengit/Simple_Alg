#include <stack>
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int j = 0;
        for(int i = 0; i < pushV.size(); i++){
            s.push(pushV[i]);
            while(!s.empty() && popV[j] == s.top()){
                s.pop();
                j++;
            }
        }
        if(s.empty())
            return true;
        else 
            return false;
    }
};