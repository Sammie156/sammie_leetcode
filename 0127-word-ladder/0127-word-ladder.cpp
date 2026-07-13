class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int steps = 1;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord)) return 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return steps;
                }

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                            cout << word << endl;
                        }
                    }

                    word[i] = original;
                }

            }

            steps++;
        }

        return 0;
    }
};