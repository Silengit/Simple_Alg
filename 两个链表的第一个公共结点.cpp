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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode *pTail1 = pHead1, *pTail2 = pHead2;
        while(pTail1){
            len1++;
            pTail1 = pTail1 -> next;
        }
        while(pTail2){
            len2++;
            pTail2 = pTail2 -> next;
        }
        pTail1 = pHead1,  pTail2 = pHead2;
        if(len1 < len2){
            for(int i = 0; i < len2 - len1; i++)
                pTail2 = pTail2 -> next;
            while(pTail2){
                if(pTail1 == pTail2)
                    return pTail1;
                else{
                    pTail1 = pTail1 -> next;
                    pTail2 = pTail2 -> next;
                }
            }
        }
        else{
            for(int i = 0; i < len1 - len2; i++)
                pTail1 = pTail1 -> next;
            while(pTail2){
                if(pTail1 == pTail2)
                    return pTail1;
                else{
                    pTail1 = pTail1 -> next;
                    pTail2 = pTail2 -> next;
                }
            }
        }
        return NULL;
    }
};