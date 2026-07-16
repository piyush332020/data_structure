class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        if(n==0) return 0;
        int mxi=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>mxi) mxi=nums[i];
            int prefixgcd=gcd(nums[i],mxi);
            ans.push_back(prefixgcd);
        }
        sort(ans.begin(),ans.end());
        long long int sum=0;
        int i=0;
        int j=n-1;
        while(i<j){
            sum+=gcd(ans[i],ans[j]);
            i++;
            j--;
        }
        return sum;
    }
};