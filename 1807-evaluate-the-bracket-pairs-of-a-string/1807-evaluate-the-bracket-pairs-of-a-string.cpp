class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string t="";
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int i=0;
        int j=0;
        while(i<s.length()){
            string temp="";
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    temp+=s[j];
                    j++;
                    i++;
                }
                if(mp.count(temp)){
                t+=mp[temp];
                }else{
                    t+='?';
                }
            }else{
                if(s[i]!=')')
                    t+=s[i];
            }
            i++;
            cout<<temp;
        }
        return t;
    }
};