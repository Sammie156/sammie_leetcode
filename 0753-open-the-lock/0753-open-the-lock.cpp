class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> combos;
        unordered_set<string> visited;

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000")) return -1;

        combos.push("0000");
        visited.insert("0000");

        int turns = 0;

        while (!combos.empty()) {
            int size = combos.size();

            for (int i = 0; i < size; i++) {
                string combo = combos.front();
                combos.pop();

                if (combo == target) return turns;

                for (int j = 0; j < 4; j++) {
                    string up = combo, down = combo;
                    up[j] = up[j] == '9' ? '0' : up[j] + 1;
                    down[j] = down[j] == '0' ? '9' : down[j] - 1;

                    if (!dead.count(up) && !visited.count(up)) {
                        visited.insert(up);
                        combos.push(up);
                    }
                    if (!dead.count(down) && !visited.count(down)) {
                        visited.insert(down);
                        combos.push(down);
                    }
                }
            }

            turns++;
        }

        return -1;
    }
};