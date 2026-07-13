class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int first = 1; first <= 9; first++) {
            int num = first;

            for (int digit = first + 1; digit <= 9; digit++) {
                num = num * 10 + digit;

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};