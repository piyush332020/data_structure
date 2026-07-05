class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>dummy=nums;
        int diff=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            while(nums[i]!=0){
                int digit=nums[i]%10;
                maxi=max(maxi,digit);
                mini=min(mini,digit);
                nums[i]=nums[i]/10;
            }
            ans=maxi-mini;
            diff=max(ans,diff);
        }
        nums=dummy;
        int sum=0;
        for(int i=0;i<dummy.size();i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            int store=0;
            while(dummy[i]!=0){
                int digit=dummy[i]%10;
                maxi=max(maxi,digit);
                mini=min(mini,digit);
                dummy[i]=dummy[i]/10;
            }
            store=maxi-mini;
            if(diff==store){
                sum+=nums[i];
            }
        }
        return sum;
    }
};