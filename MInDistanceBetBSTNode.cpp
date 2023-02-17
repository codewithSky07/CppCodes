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
    vector<int>inorder;

    void inOrderTraversal(TreeNode* root){

        // base case
        if(root == NULL) return;

        // traversal
        inOrderTraversal(root->left);
        inorder.push_back(root->val);
        inOrderTraversal(root->right);
        
    }

    int minDiffInBST(TreeNode* root) {

        inOrderTraversal(root);
        int ans = INT_MAX;
        // values are arrange in ascending order.
        // calcualte the diffrence of consicutive.
        for(int i=1;i<inorder.size();i++){
            ans = min(ans,inorder[i]-inorder[i-1]);
        }

       return ans; 
    }
};
