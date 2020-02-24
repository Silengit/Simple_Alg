#include <stack>
class Solution {
public:
    void push(int value) {
        s.push(value);
        if(min_s.size()==0)
            min_s.push(value);
        else if(value <= min_s.top())
            min_s.push(value);
    }
    void pop() {
        if(s.top() == min_s.top())
            min_s.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return min_s.top();
    }
private:
    stack<int> s;
    stack<int> min_s;
};