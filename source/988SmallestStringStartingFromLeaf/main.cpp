#include<iostream>
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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
    string dfs(TreeNode* root, string str){
        if(root == NULL)
            return str;
        str = char('a' + root->val) + str;
        if(root->left == NULL && root->right == NULL)
            return str;
        else if(root->left == NULL)
            return dfs(root->right, str);
        else if(root->right == NULL)
            return dfs(root->left, str);
            
        string left = dfs(root->left, str);
        string right = dfs(root->right, str);
        if(left < right)
            return left;
        return right;
    };
};
int main(){
    Solution sol;
    TreeNode* root = new TreeNode(0);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    // root->left->left = new TreeNode(3);

    string ans = sol.smallestFromLeaf(root);
    cout << ans << endl;
    return 0;
}