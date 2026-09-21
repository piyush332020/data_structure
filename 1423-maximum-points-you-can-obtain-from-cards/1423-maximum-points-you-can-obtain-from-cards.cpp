class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int maxsum=0;
        int leftsum=0;
        for(int i=0;i<=k-1;i++){
            maxsum+=nums[i];
        }
        leftsum=maxsum;
        int rightsum=0;
        int rightindex=nums.size()-1;
        for(int i=k-1;i>=0;i--){
            leftsum-=nums[i];
            rightsum+=nums[rightindex];
            rightindex-=1;
            maxsum=max(maxsum,rightsum+leftsum);
        }
        return maxsum;
    }
};