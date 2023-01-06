// Method 2.
class Solution {
public:
 int maxIceCream(vector<int>& costs, int coins) {

        // to get the size of freq array.
        int m = *max_element(costs.begin(),costs.end());
        // to store frequency use extra vector
        vector<int>freq(m+1,0);

        // store the freq.
        for(auto x:costs){
            freq[x]++;
        }

    // to store the ans
    int ans =0;
        // traverse on cost vector and see how many coins of that cost can be used .

        for(int cost=1;cost<=m;cost++){

            // if freq of that cost == 0 then no coin is avaibable move on..
            if(freq[cost] == 0){continue;}

            // if i > coins left so we need to break out as enough coins are not  left.
            if(cost>coins){break;}

            // else reduce the coins.

            else{
             int usedcoins = min(freq[cost],coins/cost);
                coins -= cost*usedcoins;
                ans += usedcoins;
            }
        }

        return ans;
    }
};


// Method 1.
class Solution {
public:
 int maxIceCream(vector<int>& costs, int coins) {
                // sort the costs vector
        sort(costs.begin(),costs.end());
            // to store ans;
           int ans = 0;

        // traverse and deducte the coins values.
        for(auto x:costs)
        {
            if(x<=coins){
                ans++;
                coins-=x;
            }
        }
        return ans;
    }
};
