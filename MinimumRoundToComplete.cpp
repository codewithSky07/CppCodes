class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // store the frequency in map.
        unordered_map<int,int>mp;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        // store the ans. for 3 cases..
        int ans =0;

        for(auto x:mp){
            int frequency = x.second;

            // if freq is 1 return -1, not possible.
            if(frequency == 1) return -1;

            // if frequ is divided by 3 with rem == 0
            else if(frequency%3  == 0 ) ans+= frequency/3;

            // if rem == 2 or rem == 1
            else if(frequency%3 == 1 || frequency%3 == 2){
                ans += frequency/3 + 1;
            }

        }

        return ans;

    }
};
