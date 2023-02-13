class Solution {
public:
    int countOdds(int low, int high) {
        // if both are even.
        if(low%2 == 0 && high%2 == 0) 
        return (high-low)/2;

        // if low = even , high = odd.
        else if((low%2 == 0 && high%2!=0) || (low%2 != 0 && high%2 == 0)) 
        return ((high-low-1)/2)+1;

        // if low = odd , high = odd.
        else return ((high-low-2)/2) + 2;
    }
};
