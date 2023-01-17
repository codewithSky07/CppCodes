class Solution {
public:
 int minFlipsMonoIncr(string s) {
        int countflip = 0; // 0->1 or 1->0
        int countOne = 0;

        for(auto x:s){
            if(x == '1'){countOne++;}
            else{
                // at any x == 0 calcualte whether we need it to flip it or
                // can flip all the 1 upto that point to 0. One with min val is our required flip count.
                countflip = min(++countflip,countOne);
            }
        }
        return countflip;
    }
};
