/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include<stack>
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }
        vector<int> v;
        while (s.size() > 0) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};