class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<n){
            if(nums[j]==1){
                j++;
            }else{
                if(k>0){
                    k--;
                    j++;
                }else{
                    maxlen=max(maxlen,j-i);
                    while(i<n && nums[i]!=0){
                    i++;
                }
                i++;
                k++;
                }
            }
        }
        maxlen=max(maxlen,j-i);
        return maxlen;
    }
};