class Solution {
public:
    
    static bool cmp(pair<string, int>& a,pair<string, int>& b)
{
        if(a.second == b.second){

            int val = a.first.compare(b.first);

            if(val<0) return a.second;
            else b.second;
        }
    return a.second > b.second;

}

    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string>result;
        unordered_map<string,int>mp;

        for(auto word:words){
            mp[word]++;
        }

        // sort it according to value i.e frequency.
        vector<pair<string,int>>temp;



        for (auto& it : mp)
        {
           temp.push_back(it);
        }


        sort(temp.begin(),temp.end(),cmp);

        for(int i=0;i<k;i++){
         result.push_back(temp[i].first);
        }

        return result;

    }
};
