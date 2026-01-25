#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    void travesal(TreeNode *node, vector<int>& ret) {
        if(node == nullptr) {
            return;
        }
        travesal(node->left, ret);
        travesal(node->right, ret);
        ret.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        travesal(root, ret);
        return ret;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root == nullptr) {
            return ret;
        }
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* temp = stk.top();
            stk.pop();
            ret.emplace_back(temp->val);
            if(temp->left != nullptr) {
                stk.push(temp->left);
            }
            if(temp->right != nullptr) {
                stk.push(temp->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};