class Solution {
public:
    string minWindow(string s, string p) {
         // counters declare.
        int matchingCount =0;
        int desizematchingCount = p.size();

// pointers declare
        int left =-1;
        int right=-1; 

// hash to store the count of each alphabhet in patter and substring.
 
        vector<int>phash(256,0);
        vector<int>shash(256,0);

// to store the min possible substring == ans.
    string ans = "";


       //declare the window size i.e(pattern size) && length of string s;
        int window = p.size();
        int length = s.size();


        // store frequency of pattern
        for(int i=0;i<window;i++){
            phash[p[i]]++;
        }

        // Infinite loop to continue the step upto desized output.
       while(true){

        // flags to check running of each loop.
        bool flag1=false;
        bool flag2=false;


            //acquire (move the right pointer ..)
            while(right<length-1 && matchingCount<desizematchingCount){
                right++;
                shash[s[right]]++;
                if(shash[s[right]] <= phash[s[right]]){matchingCount++;}
                flag1=true;

            }




            //collect and released (check the substring possible i.e(collect) && move the left pointer..)
           while(left<=right && matchingCount == desizematchingCount){

                // collect ..
                string temp = s.substr(left+1,right-left);

                if(ans.size() == 0 || temp.size()<ans.size()){
                    ans = temp;
                }



                left++;

                // release.
                shash[s[left]]--;


                if(shash[s[left]]<phash[s[left]]){
                    matchingCount--;
                }


                flag2=true;
            }
            if(flag2 == false && flag1 == false){break;}

        }



        return ans;




    }
};
