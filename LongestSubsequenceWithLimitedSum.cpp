class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int>prefixsum(n);

        int temp=0;
        for(int i =0;i<n;i++)
        {
           temp +=nums[i];
           prefixsum[i] = temp;
        }
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int query = queries[i];
             ans.push_back(upper_bound(prefixsum.begin(),prefixsum.end(),query)-prefixsum.begin());           
        }
        
        return ans;
    }
};
