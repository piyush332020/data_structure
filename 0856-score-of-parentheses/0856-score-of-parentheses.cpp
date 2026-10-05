class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0;
        int i = 0;

        while (i < s.length()) {

            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                st.pop();

                // "()"
                if (s[i - 1] == '(') {
                    int x = 1;

                    // Count how many '(' are still open
                    int count = st.size();

                    while (count > 0) {
                        x *= 2;
                        count--;
                    }

                    ans += x;
                }
            }

            i++;
        }

        return ans;
    }
};