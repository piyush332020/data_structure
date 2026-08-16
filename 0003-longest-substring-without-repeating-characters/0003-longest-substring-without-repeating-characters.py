from collections import Counter
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp=Counter()
        left=0
        right=0
        ans=0
        while right< len(s):
            mp[s[right]]+=1
            while(mp[s[right]]>1):
                mp[s[left]]-=1
                left+=1
            ans=max(ans,right-left+1)
            right+=1
        return ans