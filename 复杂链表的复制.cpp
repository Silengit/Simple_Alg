//Hint: clone new node right after the old one, doubling the List
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* newHead = NULL, *newTail;
        RandomListNode* pTail =  pHead;
        while(pTail){
            RandomListNode* tmp = new RandomListNode(pTail -> label);
            tmp -> next = pTail -> next;
            pTail -> next = tmp;
            pTail = tmp -> next;
        }
        pTail = pHead;
        while(pTail){
            if(pTail -> random)
                pTail -> next -> random = pTail -> random -> next;
            pTail = pTail -> next -> next;
        }
        pTail = pHead;
        while(pTail){
            if(newHead == NULL){
                newHead = newTail = pTail -> next;
            }
            else{
                newTail -> next = pTail -> next;
                newTail = newTail -> next;
            }
            pTail -> next = newTail -> next;
            pTail = pTail -> next;
        }
        return newHead;
    }
};