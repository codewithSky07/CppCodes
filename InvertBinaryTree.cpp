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
    void swap(TreeNode* root){
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        
        // base case
        if(root == NULL) return root;

        // swap
        swap(root);

        // traversal
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
