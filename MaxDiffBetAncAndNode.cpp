class Solution {
public:
    int findMaxDiff(TreeNode* root,int MaxVal,int MinVal){
        // Base condtion. leaf node end of path.
        if(root == NULL) {
            return abs(MaxVal - MinVal);
        }
        // Update the max and min
        MaxVal = max(root->val,MaxVal);
        MinVal = min(root->val,MinVal);

        // Traversal.
        int left = findMaxDiff(root->left,MaxVal,MinVal);
        int right = findMaxDiff(root->right,MaxVal,MinVal);

        return max(right,left);
    }


    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        return findMaxDiff(root,root->val,root->val);
    }
};
