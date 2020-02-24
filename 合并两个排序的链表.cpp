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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *mergeHead = NULL, *tail = NULL;
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        while(pHead1 && pHead2){
            if(pHead1 -> val < pHead2 -> val){
               if(!mergeHead){
                   mergeHead = new ListNode(pHead1 -> val);
                   tail = mergeHead;
               }
               else{
                   ListNode* tmp = new ListNode(pHead1 -> val);
                   tail -> next = tmp;
                   tail = tail -> next;
               }
               pHead1 = pHead1 -> next;
            }
            else{
               if(!mergeHead){
                   mergeHead = new ListNode(pHead2 -> val);
                   tail = mergeHead;
               }
               else{
                   ListNode* tmp = new ListNode(pHead2 -> val);
                   tail -> next = tmp;
                   tail = tail -> next;
               }
               pHead2 = pHead2 -> next;
            }
        }
        if(!pHead1)
            tail -> next = pHead2;
        else
            tail -> next = pHead1;
        return mergeHead;
    }
};