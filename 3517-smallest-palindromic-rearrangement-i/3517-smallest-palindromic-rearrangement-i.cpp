class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
        string first="";
        string middle="";
        string last="";
        for(auto &it:mp){
            int times=it.second/2;
            while(times!=0){
                ans.push_back(it.first);
                times--;
            }
            if(it.second%2!=0) middle.push_back(it.first);
        }
        first=ans;
        reverse(ans.begin(),ans.end());
        last=ans;
        return first+middle+last;

    }
};