class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int maxi=0;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty())st.push(i);
                int top=st.top();
                maxi=max(maxi,i-top);
            }
            if(s[i]=='(') st.push(i);
        }
        return maxi;
    }
};