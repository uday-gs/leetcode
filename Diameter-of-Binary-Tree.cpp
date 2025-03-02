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
int height(TreeNode* root,int &a){
    if(root == nullptr) return 0;
    int left = height(root -> left,a);
    int right = height(root -> right,a);
    a = max(a,left+right);
    return (1+max(left,right));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int a = -1;
        height(root,a);
        return a;
    }
};