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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot2)
            return false;
        else return recurseTest(pRoot1, pRoot2);
    }
    
    bool recurseTest(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1 && !pRoot2)
            return true;
        else if(pRoot1 && !pRoot2)
            return true;
        else if(!pRoot1 && pRoot2)
            return false;
        else if(pRoot1 -> val == pRoot2 -> val &&
               recurseTest(pRoot1 -> left, pRoot2 -> left) &&
               recurseTest(pRoot1 -> right, pRoot2 -> right))
            return true;
        else 
            return recurseTest(pRoot1 -> left, pRoot2) || 
            recurseTest(pRoot1 -> right, pRoot2); 
    }
};