
class Solution {
public:
    int countNodes(TreeNode* root) {

    if(root == NULL) return 0;

    int lh = countLeftHeight(root);
    int rh = countRightHeight(root);


    //this means we got a perfect tree hence it will have 2^h -1 nodes.
    if(lh == rh) return pow(2, lh) - 1;

    // 1 added for the parent one node while left and right parts are needed to calculate the values for the heights.
    return 1+countNodes(root->left)+countNodes(root->right);


  }

// calculate left height.
  int countLeftHeight(TreeNode* root)
  {
    int count=0;
    while(root)
    {
      count++;
      root = root->left;
    }
    return count;
  }

// calcualte right height.
    int countRightHeight(TreeNode* root)
  {
    int count=0;
    while(root)
    {
      count++;
      root = root->right;
    }
    return count;
  }
};
