class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int left=0;
        int ans=0;
        for(int right=0;right<s.length();right++){
            int ch=s[right];
            freq[ch]++;
            while(freq[ch]>1){
                freq[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;   
    }
};