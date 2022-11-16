class Solution {
public:
    int guessNumber(int n) {

        int left = 1;
        int right = n;

        while(left<=right){
            // calculate mid .
            int mid = left + (right-left)/2;

            // get result for mid.
            int val = guess(mid);

            if(val == 0) return mid;
            else if(val == -1 ) right = mid-1;
            else left = mid+1;
        }
        return -1;

    }
};
