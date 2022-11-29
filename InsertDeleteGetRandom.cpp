
class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    bool search(int val){
//         is present.
         if(mp.find(val)!=mp.end())
            return true;
         return false;
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
//         if already there , no need to add.
        if(search(val))
            return false;
        
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
//         if not present.we can remove.
        if(!search(val))
            return false;
        
        // pointer to the value.
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
//         rand()%v.size() : give us index between 1 to v.size()-1
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
