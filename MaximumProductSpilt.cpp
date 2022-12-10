static int MOD=1e9+7;
class Solution {
public:
 long long TotalSum=0,result=0;
    //Find total sum of the tree.
    void TotalTreeSum(TreeNode* root)
    {
        if(!root)
            return;
        TotalSum+=root->val;
        TotalTreeSum(root->left);
        TotalTreeSum(root->right);
    }

    int SubTreeSum(TreeNode* root)
//Find the totalSum under the root, including root.
    {
       if(root == NULL)
            return 0;

 //Find the sum of left and right subtree under root.
       int SumUnderLeft=SubTreeSum(root->left);
       int SumUnderRight=SubTreeSum(root->right);

//Find the max product after making left or right subtrees as seprarate tree.
       result=max({result,(TotalSum-SumUnderLeft)*SumUnderLeft,(TotalSum-SumUnderRight)*SumUnderRight});

//Return the sum of the  subtree which include current node (root node).
       return SumUnderLeft+SumUnderRight+root->val;
    }

    int maxProduct(TreeNode* root)
    {
        TotalTreeSum(root);
        SubTreeSum(root);
        return result%MOD;
    }
};
