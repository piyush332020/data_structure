class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mp;
        int count=1;
        for(char i='z';i>='a';i--){
            mp[i]=count;
            count++;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=mp[s[i]]*(i+1);
        }
        return ans;
    }
};