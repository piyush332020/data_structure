class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        for(int i=0; i + p.size() <= s.size();i++){
            unordered_map<char,int>temp=mp;
            for(int j=i;j<i+p.size();j++){
                temp[s[j]]--;
            }
            bool flag = true;
            for(auto x : temp){
                if(x.second != 0){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;
    }
};