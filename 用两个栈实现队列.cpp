class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int x;
        if (stack2.size() > 0) {
            x = stack2.top();
            stack2.pop();
            return x;
        }
        while (stack1.size() > 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        x = stack1.top();
        stack1.pop();
        return x;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};