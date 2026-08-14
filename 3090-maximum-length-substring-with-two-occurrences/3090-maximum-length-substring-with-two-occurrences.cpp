class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0;
        int len=0;
        for(int right=0;right<s.length();right++){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
            len=max(len,right-left+1);
        }
        return len;
    }
};