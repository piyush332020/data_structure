class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;

        for (int left = 0; left < nums.size(); left++) {
            int sum = 0;

            for (int right = left; right < nums.size(); right++) {
                sum += nums[right];

                int len = right - left + 1;

                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }

                if (len == r) break;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};