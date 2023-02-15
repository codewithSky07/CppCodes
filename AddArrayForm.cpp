class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
  
        for(int i=num.size()-1;i>=0;i--){
            int temp = num[i]+k;
            // value to store .
            num[i] = temp%10;
            k=temp/10; // carry.
        }

        // if k>0 that means we need to insert in front.
        while(k>0){
            num.insert(num.begin(),k%10);
            k=k/10;
        }

        return num;
     

    }
};
