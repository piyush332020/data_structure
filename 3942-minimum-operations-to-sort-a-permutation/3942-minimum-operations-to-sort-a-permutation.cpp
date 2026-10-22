class Solution {
private:
    int getRotation(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                k = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[(k + i) % n] != i) {
                return -1;
            }
        }

        return k;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int k = getRotation(nums);
        int ans = INT_MAX;

        if (k != -1) {
            ans = min(k, n - k + 2);
        }

        vector<int> arr = nums;
        reverse(arr.begin(), arr.end());

        k = getRotation(arr);

        if (k != -1) {
            ans = min(ans, min(k + 1, n - k + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};