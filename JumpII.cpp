class Solution {
public:
    int jump(vector<int>& nums) {
        int maxSofar =0;
        int currentMax = 0;
        int jump=0;

        for(int i=0;i<nums.size()-1;i++){
            maxSofar = max(maxSofar,i+nums[i]);

            if(i == currentMax){
                // we need to update the current Max and for that we need to jump.
                jump++;
                currentMax = maxSofar;
            }
        }
        return jump;
    }
};
