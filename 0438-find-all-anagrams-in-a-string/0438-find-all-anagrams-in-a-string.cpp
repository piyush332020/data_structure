class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()) return ans;
        unordered_map<char,int> mp;
        for(char ch : p) {
            mp[ch]++;
        }
        int count = p.size();
        int i = 0;
        for(int j = 0; j < s.size(); j++) {
            if(mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;
            if(j - i + 1 == p.size()) {
                if(count == 0) {
                    ans.push_back(i);
                }
                if(mp[s[i]] >= 0) {
                    count++;
                }
                mp[s[i]]++;

                i++;
            }
        }
        return ans;
    }
};