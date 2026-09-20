class Solution {
public:
    int longestValidParentheses(string s) {
        // we use a stack of indices, not ( and )
        stack<int> st;
        st.push(-1);

        int len = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                } else {
                    len = max(len, i - st.top());
                }
            }
        }

        return len;
    }
};