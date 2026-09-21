class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int zero=0;
        int j=0;
        int i=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zero++;
            }
            while(zero>k){
                if(nums[i]==0){
                    zero--;
                }
                i++;
            }
            if(zero<=k){
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};