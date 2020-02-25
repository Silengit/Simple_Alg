/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        else if(pRootOfTree -> left == NULL && pRootOfTree -> right == NULL)
            return pRootOfTree;
        TreeNode* convertedLeft = Convert(pRootOfTree -> left);
        TreeNode* convertedRight = Convert(pRootOfTree -> right);
        if(convertedLeft){
            TreeNode* leftTail = convertedLeft;
            while(leftTail->right)
                leftTail = leftTail -> right;
            leftTail -> right = pRootOfTree;
            pRootOfTree -> left = leftTail;
        }
        if(convertedRight) {
            convertedRight -> left =  pRootOfTree;
            pRootOfTree -> right = convertedRight;
        }
        if(convertedLeft == NULL)
            return pRootOfTree;
        else
            return convertedLeft;
            
    }
};