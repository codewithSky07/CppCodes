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
    
    void dfs(TreeNode* root,int val,int currDepth,int depth){
        
        if(root == NULL) return;
        
        // base 
        if(currDepth == depth-1){
            // left side.new node
            TreeNode* leftside = root->left;
            root->left = new TreeNode(val);
            root->left->left = leftside;
            
            //rightside
            TreeNode*rightside = root->right;
            root->right = new TreeNode(val);
            root->right->right = rightside;
        }
        
        // traversal
        dfs(root->left,val,currDepth+1,depth);
        dfs(root->right,val,currDepth+1,depth);
        
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // case d==1
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            
            return temp;
        }
        
        // case 2; d!=1
        dfs(root,val,1,depth);
        
        return root;
        
        
    }
};
