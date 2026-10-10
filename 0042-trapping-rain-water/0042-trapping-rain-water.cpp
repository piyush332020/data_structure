class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int pre=0;
        int suf=0;
        for(int i=0;i<nums.size();i++){
            pre=max(pre,nums[i]);
            prefix[i]=pre;
        }
        for(int i=n-1;i>=0;i--){
            suf=max(suf,nums[i]);
            suffix[i]=suf;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=min(prefix[i],suffix[i])-nums[i];
        }
        return ans;
    }
};