class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo = 0;
        bool ispresent=false;
        for(int i:nums){
            xo^=i;
            if(i!=0){
                ispresent=true;
            }
        }
        if(!ispresent) return 0;
        if(xo!=0) return nums.size();
        else return nums.size()-1;
        return 0;
    }
};