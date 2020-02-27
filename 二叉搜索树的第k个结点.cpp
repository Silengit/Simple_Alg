/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        want = NULL;
        if(pRoot == NULL)
            return want;
        num = k;
        inorder(pRoot);
        return want;
    }
    void inorder(TreeNode* node){
        if(node == NULL)
            return;
        inorder(node -> left);
        num--;
        if(num == 0)
            want = node;
        inorder(node -> right);
    }
    int num;
    TreeNode* want;
};