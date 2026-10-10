class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u'){
                count++;
            }
        }
        int left=0;
        int  ans=count;
        for(int i=k;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u'){
                count++;
            }
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' ||s[left]=='u'){
                count--;
            }
            left++;
            ans=max(ans,count);
        }
        return ans;
    }
};