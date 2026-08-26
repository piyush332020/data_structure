class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int onecount=0;
        int left=0;
        int temp=s.length();
        for(int right=0;right<s.length();right++){
            if(s[right]=='1'){
                onecount++;
            }
            while(onecount>=k){
                string curr = s.substr(left, right - left + 1);
                if (ans == "" || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) {
                    ans=curr;
                }
                if(s[left]=='1'){
                    onecount--;
                }
                left++;
            }
        }
        return ans;
    }
};