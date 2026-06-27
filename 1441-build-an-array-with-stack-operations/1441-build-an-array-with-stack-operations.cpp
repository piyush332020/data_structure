class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> s;
        int i = 0;
        int j = 1;

        while (j <= n && i < target.size()) {
            s.push(j);
            ans.push_back("Push");

            if (target[i] == s.top()) {
                i++;
            } else {
                ans.push_back("Pop");
                s.pop();
            }

            j++;
        }

        return ans;
    }
};