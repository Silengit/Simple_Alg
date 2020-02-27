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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == NULL)
            return result;
        int ctr = 1, i = 0, depth = 0;
        queue<TreeNode*> nodes;
        stack<int> s;
        queue<int> q;
        nodes.push(pRoot);
        while(!nodes.empty()){
            i++;
            TreeNode *cur = nodes.front();
            nodes.pop();
            if(depth % 2 == 1)
                s.push(cur -> val);
            else
                q.push(cur -> val);
            if(cur -> left != NULL) nodes.push(cur -> left);
            if(cur -> right != NULL) nodes.push(cur -> right);
            if(i == ctr){
                ctr = nodes.size();
                i = 0;
                if(depth % 2 == 1){
                    vector<int> v;
                    while(!s.empty()){
                        v.push_back(s.top());
                        s.pop();
                    }
                    result.push_back(v);
                }
                else{
                    vector<int> v;
                    while(!q.empty()){
                        v.push_back(q.front());
                        q.pop();
                    }
                    result.push_back(v);
                }
                depth++;
            }
        }
        return result;
    }
};