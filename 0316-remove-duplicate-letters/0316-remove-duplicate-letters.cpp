class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> last;
        unordered_map<char,bool>used;
        for(int i=0;i<s.length();i++){
            last[s[i]]=i;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(used[ch]){
                continue;
            }
            while(!ans.empty() && ans.back()> ch && last[ans.back()] > i ){
                used[ans.back()]=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            used[ch]=true;
        }
        return ans;
    }
};