class Solution {
public:
    int MOD = 1e9 + 7; // Define MOD to handle large sums and avoid overflow.

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0; // Pointers for iterating through nums1 and nums2.
        long long sum1 = 0,
                  sum2 = 0;   // Sums to accumulate path values from each array.
        int n = nums1.size(); // Size of the first array.
        int m = nums2.size(); // Size of the second array.
        long long int ans = 0; // Variable to store the final result.

        // Traverse both arrays simultaneously until we reach the end of one of
        // them.
        while (i < n && j < m) {
            // If nums1[i] is smaller, accumulate sum1 and move to the next
            // element in nums1.
            if (nums1[i] < nums2[j]) {
                sum1 = (sum1 + nums1[i]) % MOD;
                i++;
            }
            // If nums2[j] is smaller, accumulate sum2 and move to the next
            // element in nums2.
            else if (nums2[j] < nums1[i]) {
                sum2 = (sum2 + nums2[j]) % MOD;
                j++;
            }
            // If both elements are equal (common point), take the maximum of
            // sum1 and sum2, add the common element, and move both pointers
            // forward.
            else {
                ans = (ans + max(sum1, sum2) + nums2[j]) % MOD;
                i++;
                j++;
                // Reset sum1 and sum2 after handling the common point.
                sum1 = 0;
                sum2 = 0;
            }
        }

        // If there are remaining elements in nums1, add them to sum1.
        while (i < n) {
            sum1 = (sum1 + nums1[i]) % MOD;
            i++;
        }

        // Example 3  nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10] , if nothing is equal then sum2 and sum1 max of both will be ans. In this case no common point is there so we have ans = 0 uptill end of nums1 traversal.

        // If there are remaining elements in nums2, add them to sum2.
        while (j < m) {
            sum2 = (sum2 + nums2[j]) % MOD;
            j++;
        }

        // After finishing both arrays, add the maximum of the remaining sum1 or
        // sum2 to the result.
        ans = (ans + max(sum1, sum2)) % MOD;

        return ans; // Return the final maximum sum mod 10^9 + 7.
    }
};
