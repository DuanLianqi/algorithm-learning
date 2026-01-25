#include <vector>
#include <stack>
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
        ret.push_back(node->val);
        travesal(node->left, ret);
        travesal(node->right, ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        travesal(root, ret);
        return ret;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
            if(temp->right != nullptr) {
                stk.push(temp->right);
            }
            if(temp->left != nullptr) {
                stk.push(temp->left);
            }
        }
        return ret;
    }
};
