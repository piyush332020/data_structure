class Solution {
private:
    int binarysearch(int endpoint, vector<vector<int>>& intervals) {
        int low = 0;
        int high = intervals.size() - 1;
        int result = intervals.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > endpoint) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    pair<long long, vector<int>>
    solve(int i, int k, vector<vector<int>>& intervals, vector<int>& nextindex,vector<vector<pair<long long, vector<int>>>>& dp) {
        if (i == intervals.size() || k == 0) {
            return {0, {}};
        }
        if (dp[i][k].first != -1) {
            return dp[i][k];
        }
        auto skip = solve(i + 1, k, intervals, nextindex, dp);
        auto take = solve(nextindex[i], k - 1, intervals, nextindex, dp);
        take.first += intervals[i][2];
        take.second.push_back(intervals[i][3]);
        sort(take.second.begin(), take.second.end());
        if (take.first > skip.first) {
            return dp[i][k] = take;
        }
        if (take.first < skip.first) {
            return dp[i][k] = skip;
        }
        if (take.second < skip.second) {
            return dp[i][k] = take;
        }
        return dp[i][k] = skip;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> nextindex(n);
        for (int i = 0; i < n; i++) {
            nextindex[i] = binarysearch(intervals[i][1], intervals);
        }
        vector<vector<pair<long long, vector<int>>>> dp(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));
        return solve(0, 4, intervals, nextindex, dp).second;
    }
};