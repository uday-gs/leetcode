/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root,bool &ans){
        if(root == nullptr) return 0;
        int left_tree = height(root -> left,ans);
        int right_tree = height(root -> right,ans);
        int diff = abs(left_tree - right_tree);
        if(diff > 1) ans = false;
        return (1 + max(left_tree,right_tree));
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        height(root,ans);
        return ans;
        
    }
};