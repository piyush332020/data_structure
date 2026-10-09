
class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count += 2;

                if (count % 2 != 0) {
                    ans++;
                    count--;
                }
            } else {
                count--;

                if (count < 0) {
                    ans++;
                    count = 1;
                }
            }
        }

        return ans + count;
    }
};