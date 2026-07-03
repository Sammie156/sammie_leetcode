class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        if (edges.empty()) return -1;
        
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        vector<int> candidates;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
            candidates.push_back(cost);
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);
            for (const auto& [v, w] : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        const long long INF = 1e18;
        auto canReach = [&](int threshold) -> bool {
            vector<long long> dist(n, INF);
            dist[0] = 0;
            
            for (int u : topoOrder) {
                if (dist[u] == INF || !online[u]) continue;
                for (const auto& [v, w] : adj[u]) {
                    if (!online[v]) continue;
                    if (w >= threshold) {
                        if (dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        
        int left = 0, right = (int)candidates.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(candidates[mid])) {
                ans = candidates[mid];
                left = mid + 1; // Try to find a larger minimum edge cost
            } else {
                right = mid - 1; // Threshold too high, reduce it
            }
        }
        
        return ans;
    }
};