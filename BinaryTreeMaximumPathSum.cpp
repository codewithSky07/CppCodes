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
    int sum =INT_MIN;
    int maxPathSum(TreeNode* root) {
        
        calcualteMaxPathSum(root);
        return sum;
        
    }
    // max sum path including root of the tree.
    int calcualteMaxPathSum(TreeNode* root){
        if(root == NULL) return 0;
        
        //if lhsum is comming -ve so we will return 0;
        
      int  lhsum = max(0,calcualteMaxPathSum(root->left));
      int  rhsum = max(0,calcualteMaxPathSum(root->right));
        
        
        //updating the value in the sum.. // maximum sum upto now.(can be subtree sum)
        sum = max(sum,root->val+lhsum+rhsum);
        
        
        //returning the maxximum sum possible.. using which path.
        return max(lhsum,rhsum) + root->val;
    }
};
