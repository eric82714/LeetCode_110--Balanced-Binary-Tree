/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isBalanced(struct TreeNode* root){
    return (is_balanced_helper(root) != -1);
}
    
int is_balanced_helper(struct TreeNode* root) {
    if(root == NULL) return 0;
    
    int left_height = is_balanced_helper(root->left);
    if(left_height == -1) return -1;

    int right_height = is_balanced_helper(root->right);
    if(right_height == -1) return -1;

    if(abs(left_height - right_height) > 1) return -1;
    
    return 1 + fmax(left_height, right_height);
}
