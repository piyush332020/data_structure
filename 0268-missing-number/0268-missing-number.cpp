class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1);
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]=1;
        }
        int fin=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=1){
                fin=i;
            }
        }
        return fin;
    }
};