class Solution {
private:
    void generate(int n,int open,int close,string str,vector<string>& ans){
        if(str.length()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            generate(n,open+1,close,str + "(",ans);
        }
        if(close<open){
            generate(n,open,close+1,str + ")",ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        generate(n,0,0,str,ans);
        return  ans;
    }
};