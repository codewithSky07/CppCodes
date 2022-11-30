class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        
//         Store the frequecny.
        for(auto num:arr){
            mp[num]++;
        }
        
//         check the count and insert in unordered set.
        unordered_set<int>set;
        
        for(auto it:mp){
            int freq = it.second;
            set.insert(freq);
        }
        
//         if size of mp is same as set that means all have unique freq.
        return set.size() == mp.size();
        
    }
};
