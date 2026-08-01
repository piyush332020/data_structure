class Solution {
private:
    bool solve(int i, int j, vector<int>& nums,int onesum, int twosum, bool player1) {
        if(i > j) {
            return onesum >= twosum;
        }
        if(player1) {
            bool pickFirst = solve(i + 1, j, nums,onesum + nums[i], twosum, false);
            bool pickLast = solve(i, j - 1, nums,onesum + nums[j], twosum, false);
            return pickFirst || pickLast;
        }
        else {
            bool pickFirst = solve(i + 1, j, nums,onesum, twosum + nums[i], true);
            bool pickLast = solve(i, j - 1, nums,onesum, twosum + nums[j], true);
            return pickFirst && pickLast;
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums,0,0,true);
    }
};