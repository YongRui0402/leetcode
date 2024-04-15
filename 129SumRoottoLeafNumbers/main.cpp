#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
        
    }
    int dfs(TreeNode* node, int pathSum) {
        if (!node)
            return 0;
        else
            pathSum = pathSum * 10 + node->val;
        
        if (!node->left && !node->right)
            return pathSum;
        
        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
    return 0;
}