class Solution {
public:
    void djikstra(
        vector<vector<pair<int, int>>>& adj,
        vector<int>& dist,
        int source
    ) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& [neighbour, weight]: adj[node]) {
                int newDist = currDist + weight;
                if (newDist < dist[neighbour]) {
                    dist[neighbour] = newDist;
                    pq.push({newDist, neighbour});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge: times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        djikstra(adj, dist, k);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};