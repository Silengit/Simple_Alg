/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        int i;
        vector<int> pre_left, pre_right, vin_left, vin_right;
        for (i = 0; i < int(vin.size()); i++) {
            if (vin[i] == pre[0])
                break;
            else {
                pre_left.push_back(pre[i + 1]);
                vin_left.push_back(vin[i]);
            }
        }
        for (int j = i + 1; j < int(vin.size()); j++) {
            pre_right.push_back(pre[j]);
            vin_right.push_back(vin[j]);
        }
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};