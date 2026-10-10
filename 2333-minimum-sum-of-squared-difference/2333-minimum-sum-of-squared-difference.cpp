
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long total = (long long)k1 + k2;
        vector<int> diff;
        int maxi = 0;
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int dif = abs(nums1[i] - nums2[i]);
            diff.push_back(dif);
            maxi = max(maxi, dif);
            sum += dif;
        }

        if (total >= sum) return 0;

        vector<int> freq(maxi + 1, 0);

        for (int i = 0; i < diff.size(); i++) {
            freq[diff[i]]++;
        }

        for (int i = maxi; i > 0 && total > 0; i--) {
            int cnt = min((long long)freq[i], total);

            freq[i] -= cnt;
            freq[i - 1] += cnt;
            total -= cnt;
        }

        long long ans = 0;

        for (int i = 1; i <= maxi; i++) {
            ans += 1LL * freq[i] * i * i;
        }

        return ans;
    }
};
