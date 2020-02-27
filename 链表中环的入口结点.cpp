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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<ListNode*, int> dict;
        while(pHead){
            dict[pHead] ++;
            if(dict[pHead] == 2)
                return pHead;
            pHead = pHead -> next;
        }
        return NULL;
    }
};