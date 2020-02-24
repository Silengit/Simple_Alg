#include <stack>
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        stack<ListNode*> s;
        while(pListHead != NULL){
            s.push(pListHead);
            pListHead = pListHead -> next;
        }
        if(k > s.size() || k == 0)
            return NULL;
        while(k-- > 1)
            s.pop();
        return s.top();
    }
};