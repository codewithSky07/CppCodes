class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin(),nums.end());
        int sum = 0;
        vector<int> prefixsum;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            prefixsum.push_back(sum);           
        }
        
        vector<int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                  // wherever we got the max subsequence sum for i just update that
                if(prefixsum[j] <= queries[i]) 
                    ans[i] = j+1;        
                else break;
            }
        }
        return ans;
    }
};
