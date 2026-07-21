class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int onecount=0;
        for(auto i:s){
            if(i=='1') onecount++;
        }
        int i=0;
        vector<int>zero;
        while(i<s.length()){
            int count=0;
            if(s[i]=='0'){
                while(i<s.length() && s[i]=='0'){
                    count++;
                    i++;
                }
                zero.push_back(count);
            }
            else{
                i++;
            }
        }
        int maximum=0;
        for(int i=0;i+1<zero.size();i++){
            maximum=max(maximum,zero[i]+zero[i+1]);
        }
        return maximum+onecount;
    }
};