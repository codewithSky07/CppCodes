class Solution {
public:
 // to store the order of
        unordered_map<char,int>mp;
    bool correctOrder(string a,string b){
        int n=min(a.size(),b.size());

        for(int i=0;i<n;i++){
            if(mp[a[i]]<mp[b[i]]) return true;
            else if(mp[a[i]]>mp[b[i]]) {
                    return false;
            }
        }
        // if they are lexicographically.check if b is substring of a
        if(a.size()>b.size() &&(a.find(b)!= string::npos)){
            return false;
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }

       

        for(int i=0;i<words.size()-1;i++){
            if(!correctOrder(words[i],words[i+1])){return false;}
        }
        return true;
    }
};
