/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (is_balanced_helper(root) != -1);
    }
    
    int is_balanced_helper(TreeNode* root) {
        if(root == NULL) return 0;
    
        int left_height = is_balanced_helper(root->left);
        if(left_height == -1) return -1;

        int right_height = is_balanced_helper(root->right);
        if(right_height == -1) return -1;

        if(abs(left_height - right_height) > 1) return -1;

        return 1 + max(left_height, right_height);
    }
};
