/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        ListNode *newHead = new ListNode(0);
        newHead -> next = pHead;
        ListNode *pre = newHead, *current = pHead;
        while(current){
            if(current -> next && current -> val == current -> next ->val){
                while(current -> next && current -> val == current -> next -> val)
                    current = current -> next;
                pre -> next = current -> next;
                current = current -> next;
            }
            else{
                pre = current;
                current = current -> next;
            }
        }
        return newHead -> next;
    }
};