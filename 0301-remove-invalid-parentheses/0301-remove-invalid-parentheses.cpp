class Solution {
private:
    void generate(int i,int count,int remove,string& temp,
                  unordered_set<string>& ans,string& s,int& maxlen){

        if(count<0) return;

        if(i>=s.length()){
            if(count==0 && remove==0){
                int len=temp.length();

                if(len>maxlen){
                    ans.clear();
                    ans.insert(temp);
                    maxlen=len;
                }
                else if(len==maxlen){
                    ans.insert(temp);
                }
            }
            return;
        }

        if(remove>0)
            generate(i+1,count,remove-1,temp,ans,s,maxlen);

        if(s[i]=='('){
            temp.push_back(s[i]);
            generate(i+1,count+1,remove,temp,ans,s,maxlen);
            temp.pop_back();
        }
        else if(s[i]==')'){
            temp.push_back(s[i]);
            generate(i+1,count-1,remove,temp,ans,s,maxlen);
            temp.pop_back();
        }
        else{
            temp.push_back(s[i]);
            generate(i+1,count,remove,temp,ans,s,maxlen);
            temp.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s){

        int count=0;
        int remove=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                count++;
            else if(s[i]==')'){
                if(count>0)
                    count--;
                else
                    remove++;
            }
        }

        remove+=count;

        unordered_set<string> ans;
        int maxlen=0;
        string temp="";

        generate(0,0,remove,temp,ans,s,maxlen);

        vector<string> answer;

        for(auto x:ans)
            answer.push_back(x);

        return answer;
    }
};