class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> map;

        for (char ch: text) {
            map[ch]++;
        }

        return min({map['b'], map['a'], map['l']/2, map['o']/2, map['n']});
    }
};