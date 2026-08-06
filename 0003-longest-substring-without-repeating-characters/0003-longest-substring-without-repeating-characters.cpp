class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;

        unordered_map<char,int>freq;

        while(j < s.size()) {
            freq[s[j]]++;

            while(freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};