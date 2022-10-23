class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=1;
        vector<int>result;

        // find the duplicate.
        for(auto x:nums){
            // duplicate.
            if(nums[abs(x)-1]<0){
                dup =abs(x);
            }else{
                nums[abs(x)-1] *=-1;
            }

        }
        result.push_back(dup);

        // find the missing..
        for(int i=1;i<nums.size();i++){

            if(nums[i]>0){
                 // missing.
                missing = i+1;
            }

        }
        result.push_back(missing);
        return result;
    }
};
