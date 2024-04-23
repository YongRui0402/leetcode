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