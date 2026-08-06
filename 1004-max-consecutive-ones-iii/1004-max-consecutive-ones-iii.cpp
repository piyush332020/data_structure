class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int len=0;
        int i=0;
        int zero=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j]==0) zero++;
            while(zero>k){
                if(nums[i]==0){
                    zero--;
                }
                i++;
            }
            if(zero<=k){
                len=j-i+1;
                maxlen=max(len,maxlen);
            }
            j++;
        }
        return maxlen;
    }
};