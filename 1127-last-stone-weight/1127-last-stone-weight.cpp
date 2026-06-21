class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone: stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x == y) {
                continue;
            } else {
                int diff = y - x;
                pq.push(diff);
            }
        }

        if (pq.size() == 0) return 0;
        else return pq.top();
    }
};