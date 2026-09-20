class Solution {
public:
    string decodeString(string s) {
        int i = 0;

        return solve(s, i);
    }

    string solve(string& s, int& i) {
        string res = "";
        int num = 0;

        while (i < s.size()) {
            char ch = s[i];


            if (isdigit(ch)) {
                num = num*10 + (ch - '0');
                i++;
            } else if (ch == '[') {
                i++;
                string recur = solve(s, i);
                for (int k = 0; k < num; k++) {
                    res += recur;
                }
                num = 0;
            } else if (ch == ']') {
                i++;
                return res;
            } else {
                res += ch;
                i++;
            }
        }

        return res;
    }
};