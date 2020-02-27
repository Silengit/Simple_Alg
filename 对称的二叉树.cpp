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
    bool isSymmetrical(TreeNode* pRoot)
    {
        TreeNode *newRoot = reverse(pRoot);
        return isEqual(pRoot, newRoot);
    }
    
    bool isEqual(TreeNode* pRoot, TreeNode* newRoot){
        if(pRoot == NULL && newRoot == NULL)
            return true;
        else if(pRoot == NULL || newRoot == NULL)
            return false;
        else if(pRoot -> val == newRoot -> val)
            return isEqual(pRoot->left, newRoot->left) && 
            isEqual(pRoot->right, newRoot->right);
        else
            return false;
    }

    TreeNode *reverse(TreeNode *pRoot){
        if(pRoot == NULL)
            return NULL;
        else{
            TreeNode *newRoot = new TreeNode(pRoot -> val);
            newRoot -> left = reverse(pRoot -> left);
            newRoot -> right = reverse(pRoot -> right);
            TreeNode * tmp = newRoot -> left;
            newRoot -> left = newRoot -> right;
            newRoot -> right = tmp;
            return newRoot;
        }
    }
};