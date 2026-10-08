class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (st.empty()) {
                    start = i + 1; 
                }
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    ans += s.substr(start, i - start);
                }
            }
        }

        return ans;
    }
};
