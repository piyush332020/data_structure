class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpt;
        unordered_map<char,int>mps;
        int left=0;
        int start=0;
        int count=INT_MAX;
        for(char ch:t){
            mpt[ch]++;
        }
        int formed=0;
        for(int right=0;right<s.length();right++){
            int ch=s[right];
            if(mpt.find(ch)!=mpt.end()){
                mps[ch]++;
                if(mps[ch] == mpt[ch]) {
                    formed++;
                }
            }
            while(formed==mpt.size()){
                if(right-left+1<count){
                    count=right-left+1;
                    start=left;
                }
                char leftchar=s[left];
                if(mpt.find(leftchar)!=mpt.end()){
                    if(mps[leftchar]==mpt[leftchar]){
                        formed--;
                    }
                    mps[leftchar]--;
                }
                left++;
            }
        }
        if(count==INT_MAX) return "";
        return s.substr(start,count);
    }
};