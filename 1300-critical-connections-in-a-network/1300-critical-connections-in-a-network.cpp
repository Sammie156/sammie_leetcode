class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        int timer = 0;

        vector<vector<int>> res;

        vector<vector<int>> adj(n);

        for (auto& connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i, i, adj, tin, low, timer, res);
            }
        }

        return res;
    }

    void dfs(
        int node,
        int parent,
        vector<vector<int>>& adj,
        vector<int>& tin,
        vector<int>& low,
        int& timer,
        vector<vector<int>>& res
    ) {

        tin[node] = low[node] = timer++;

        for (int neighbour: adj[node]) {
            if (parent == neighbour) continue;

            if (tin[neighbour] == -1) {
                dfs(neighbour, node, adj, tin, low, timer, res);

                low[node] = min(low[node], low[neighbour]);

                if (low[neighbour] > tin[node]) {
                    res.push_back({node, neighbour});
                }

            } else {
                low[node] = min(low[node], tin[neighbour]);
            }
        }
    }
};