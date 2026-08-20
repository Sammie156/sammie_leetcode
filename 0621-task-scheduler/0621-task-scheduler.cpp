class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        vector<int> freq(26, 0);
        for (char task: tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int ans = 0;

        while (!pq.empty()) {
            vector<int> temp;
            int slots = 0;

            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();

                    slots++;
                }
            }

            for (int remain: temp) {
                if (remain > 0) {
                    pq.push(remain);
                }
            }

            ans += pq.empty() ? slots: n + 1;
        }

        return ans;
    }
};