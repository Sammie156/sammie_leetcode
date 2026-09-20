class Solution {
public:
    int calculate(string s) {
        long long result = 0, sign = 1, num = 0;

        stack<int> st;

        for (char ch: s) {
            if (isdigit(ch)) {
                num = num*10 + (ch - '0');
            } else if (ch == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (ch == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * num;
                num = 0;

                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }

        return (int)result + sign*num;
    }
};