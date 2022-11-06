class Solution {
public:
    string orderlyQueue(string s, int k) {

        // simply arrange or sort the string..
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
  //when smallest alphabhet comes on index 0.
        string res = s;
        for (int i = 1; i < s.length(); i++)
            res = min(res, s.substr(i) + s.substr(0, i));
        return res;
    }
};
