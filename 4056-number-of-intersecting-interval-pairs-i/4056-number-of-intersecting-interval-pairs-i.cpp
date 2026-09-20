class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (intervals[mid][0] <= intervals[i][1])
                    lo = mid + 1;
                else
                    hi = mid;
            }

            ans += lo - (i + 1);
        }

        return ans;
    }
};