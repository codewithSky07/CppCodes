class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i>reachable)return false;
            else {
                reachable = max(reachable,i+nums[i]);
            }
        }

        return true;
    }
};
