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
    char* Serialize(TreeNode* pRoot) {
        string result;
        if (pRoot == NULL)
            return NULL;
        int ctr = 1, i = 0, depth = 0;
        queue<TreeNode*> nodes;
        nodes.push(pRoot);
        while (!nodes.empty()) {
            i++;
            TreeNode* cur = nodes.front();
            nodes.pop();
            if (cur->left != NULL) nodes.push(cur->left);
            if (cur->right != NULL) nodes.push(cur->right);
            if (i == ctr) {
                ctr = nodes.size();
                i = 0;
                depth++;
            }
        }
        nodes.push(pRoot);
        for (i = 0; i < pow(2, depth) - 1; i++) {
            TreeNode* cur = nodes.front();
            if (cur->val == -10001)
                result += "#!";
            else result += to_string(cur->val) + "!";
            nodes.pop();
            if (cur->left == NULL) {
                TreeNode* tmp = new TreeNode(-10001);
                cur->left = tmp;
                nodes.push(tmp);
            }
            else nodes.push(cur->left);
            if (cur->right == NULL) {
                TreeNode* tmp = new TreeNode(-10001);
                cur->right = tmp;
                nodes.push(tmp);
            }
            else {
                nodes.push(cur->right);
            }
        }
        char* c = strdup(result.c_str());
        return c;
    }

    TreeNode* Deserialize(char* str) {
        if (str == NULL)
            return NULL;
        vector<TreeNode*> nodes;
        int i = 0;
        while (i < strlen(str)){
            string val;
            int x;
            for (; str[i] != '!'; i++)
                val += str[i];
            if (str[i - 1] == '#')
                x = -10001;
            else
                x = stoi(val);
            TreeNode* tmp = new TreeNode(x);
            nodes.push_back(tmp);
            i++;
        }
        for (auto& item : nodes)
            cout << item->val << " ";
        TreeNode* root = nodes[0];
        TreeNode* tmp = root;
        for (int j = 0; j < nodes.size()/2; j++) {
            if (nodes[j]->val == -10001)
                continue;
            if(nodes[2 * j + 1]->val != -10001) nodes[j]->left = nodes[2 * j + 1];
            if (nodes[2 * j + 2]->val != -10001) nodes[j]->right = nodes[2 * j + 2];
        }
        return root;
    }
};