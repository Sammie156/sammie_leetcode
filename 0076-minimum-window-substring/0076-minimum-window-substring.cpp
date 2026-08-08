class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int need[128] = {};
        int window[128] = {};

        for (char ch : t) {
            need[ch]++;
        }

        int have = 0, required = 0, left = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int bestLen = INT_MAX, bestStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            window[ch]++;

            if (window[ch] == need[ch]) {
                have++;
            }

            while (have == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                window[s[left]]--;

                if (window[s[left]] < need[s[left]]) {
                    have--;
                }

                left++;
            }
        }

        if (bestLen == INT_MAX) return "";

        return s.substr(bestStart, bestLen);
    }
};