class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int,int>> ans;
        int n = arr.size();
        int left = 0;
        int sum = 0;
        for(int right = 0; right < n; right++) {
            sum += arr[right];
            while(sum > target) {
                sum -= arr[left];
                left++;
            }
            if(sum == target) {
                ans.push_back({left,right});
            }
        }
        int mini = INT_MAX;
        int best = INT_MAX;

        int j = 0;

        for(int i = 0; i < ans.size(); i++) {
            while(j < i && ans[j].second < ans[i].first) {
                int len = ans[j].second - ans[j].first + 1;
                best = min(best, len);
                j++;
            }
            if(best != INT_MAX) {
                int currLen = ans[i].second - ans[i].first + 1;
                mini = min(mini, best + currLen);
            }
        }
        if(mini == INT_MAX)
            return -1;
        return mini;
    }
};