class Solution {
private:
    int solve(int i,int j,vector<int>& nums){
        if(i==j) return nums[i];
        //include
        int includefirst=nums[i]-solve(i+1,j,nums);
        int includelast=nums[j]-solve(i,j-1,nums);
        return max(includefirst,includelast);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size()-1;
        int diff=solve(0,n,nums);
        if(diff>=0) return true;
        return  false;
    }
};