/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        if(pNode -> right == NULL){
            TreeLinkNode *p = pNode -> next;
            if(p == NULL)
                return NULL;
            while(p && p -> left != pNode){
                pNode = p;
                p = p -> next;
            }
            return p;
        }
        else{
            pNode = pNode -> right;
            while(pNode -> left != NULL)
                pNode = pNode -> left;
            return pNode;
        }
    }
};