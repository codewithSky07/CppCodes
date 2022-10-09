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
    
    void inorder(TreeNode* root,vector<int>&store){
        
        if(root == NULL) return ;
        
        // left ,root,right
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
        
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>store;
        inorder(root,store);
        
        // two pointers.
        
        int start = 0;
        int end = store.size()-1;
        
        while(start<end){
            int temp = store[start]+store[end];
            
            if(temp == k) return true;
            
            else if(temp<k) start++;
            else end--;
            
        }
        
        return false;
        
        
    }
};
