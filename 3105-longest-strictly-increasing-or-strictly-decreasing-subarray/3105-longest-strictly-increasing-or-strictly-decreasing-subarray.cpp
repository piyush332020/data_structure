
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int ansG = 1;
        int ansD = 1;

        // For increasing
        while (right < nums.size()) {
            if (nums[right - 1] < nums[right]) {
                right++;
            } else {
                ansG = max(ansG, right - left);
                left = right;
                right++;
            }
        }
        ansG = max(ansG, right - left);

        left = 0;
        right = 1;

        // For decreasing
        while (right < nums.size()) {
            if (nums[right - 1] > nums[right]) {
                right++;
            } else {
                ansD = max(ansD, right - left);
                left = right;
                right++;
            }
        }
        ansD = max(ansD, right - left);

        return max(ansG, ansD);
    }
};
