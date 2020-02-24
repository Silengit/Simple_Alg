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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *newHead = NULL;
        while(pHead != NULL){
            if(!newHead){
                newHead = new ListNode(pHead -> val);
                newHead -> next = NULL;
            }
            else{
                ListNode *tmp = new ListNode(pHead -> val);
                tmp -> next = newHead;
                newHead = tmp;
            }
            pHead = pHead -> next;
        }
        return newHead;
    }
};