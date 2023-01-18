class Solution {
public:

    int kadane(vector<int>& nums) {
        
        //if(nums.size() == 1) return nums[0];
        
        int Maxsofar = INT_MIN;
        int currmax = 0;
        
        for(auto i:nums){
            currmax += i;
            
             //will run for atleast one case 
            if(currmax >Maxsofar){
                Maxsofar = max(Maxsofar,currmax);
            }
            
            if(currmax<0){
                currmax =0;
            }
        }
        
        return Maxsofar;
        
    }

    int maxSubarraySumCircular(vector<int>& nums) {


          // for positive nums.
        int maxsubarraySum = kadane(nums);
        
        // reverse the nums vector and then calculate the maxsum_array. == minsum_array of orignal.
        int countpositive =0;
        int total_sum_reverse =0;
        int minvalue_reverse =INT_MAX;
        

        for(int i=0;i<nums.size();i++)
        {
             nums[i]= -1*nums[i];
            //  count positive == count negative .
             if(nums[i]>0){countpositive++;}
             total_sum_reverse +=nums[i];
             minvalue_reverse = min(minvalue_reverse,nums[i]);
        }

        // all negative return min -ve value  == maxpositive value.
        if(countpositive == nums.size()){
            return -1*(minvalue_reverse);
        }

        
       int maxsubarraySum_reverse = kadane(nums);
       
       int reverse_ans = -1 * (total_sum_reverse - maxsubarraySum_reverse);


       return max(maxsubarraySum,reverse_ans);
        
    }
};
