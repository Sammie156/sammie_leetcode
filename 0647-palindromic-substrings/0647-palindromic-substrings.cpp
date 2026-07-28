class Solution {
public:
    int expandAroundCenter(int left, int right, string s) {
        int n = s.size();

        int count = 0;

        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            count += expandAroundCenter(i, i, s);
            count += expandAroundCenter(i, i + 1, s);
        }

        return count;
    }
};