class Solution {
public:
    int minMoves(vector<int>& nums){
        int i;
        int ans=0;
        int minEle=*min_element(nums.begin(),nums.end());

        for(i=0;i<nums.size();i++)
        {
            int diff=nums[i]-minEle;

            ans=ans+diff;
        }
        return ans;
    }
};