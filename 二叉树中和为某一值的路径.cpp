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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> trace;
        DFS(root, expectNumber, res, trace);
        return res;
    }
    
    void DFS(TreeNode* node,int num, vector<vector<int>> &res, vector<int> &trace){
        if(node == NULL)
            return;
        trace.push_back(node -> val);
        if(node -> left == NULL && node -> right == NULL){
            if(node -> val == num){
                vector<int> right_trace = trace;
                res.push_back(right_trace);
            }
        }
        DFS(node -> left, num - node -> val, res, trace);
        DFS(node -> right, num - node -> val, res, trace);
        trace.pop_back();
    }
    
};