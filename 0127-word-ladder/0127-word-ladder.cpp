class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        if (!words.count(endWord)) return 0;

        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) return steps;

                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;

                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }

                    word[j] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};