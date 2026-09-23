class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int target=total-x;
        if(target==0) return nums.size();
        if(target<0) return -1;
        int left=0;
        int currlen=-1;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>target && left<=right){
                sum-=nums[left];
                left++;
            }
            if(sum==target){
                currlen=max(currlen,right-left+1);
            }
        }
        if(currlen==-1){
            return -1;
        }
        return nums.size()-currlen;
    }
};