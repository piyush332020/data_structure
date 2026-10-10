
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long total = (long long)k1 + k2;
        unordered_map<int, long long> freq;
        int maxi = 0;
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int dif = abs(nums1[i] - nums2[i]);

            freq[dif]++;
            maxi = max(maxi, dif);
            sum += dif;
        }

        if (total >= sum) return 0;

        for (int i = maxi; i > 0 && total > 0; i--) {
            if (freq[i] == 0) continue;

            long long cnt = min(total, freq[i]);

            freq[i] -= cnt;
            freq[i - 1] += cnt;
            total -= cnt;
        }

        long long ans = 0;

        for (auto it : freq) {
            ans += it.second * it.first * it.first;
        }

        return ans;
    }
};
