class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
 {

        //1. Store the values in the map..
        map<string,vector<string>>mp;

        for(int i=0;i<str.size();i++)
        {
            string s = str[i];
            sort(s.begin(),s.end());

            mp[s].push_back(str[i]);
        }
  

    //2. storing of the ans.
        //size of the ans will be the no. of the rows. in mp.
        vector<vector<string>> ans(mp.size());
        int index =0;
        for(auto x:mp)
        {
            //to store the anagrams or same items together.
            auto temp = x.second;

            for(auto x:temp)
            {
                ans[index].push_back(x);
            }

            index++;

        }

        return ans;

    }
};
