class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);


            degree[u]++;
            degree[v]++;
        }

        int remainingNodes = n;

        queue<int> layers;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) layers.push(i);
        }

        while (remainingNodes > 2) {
            int size = layers.size();

            for (int i = 0; i < size; i++) {
                int node = layers.front();
                layers.pop();

                for (int neighbour: graph[node]) {
                    degree[neighbour]--;
                    if (degree[neighbour] == 1) {
                        layers.push(neighbour);
                    }
                }
            }

            remainingNodes -= size;
        }

        vector<int> res;

        while (!layers.empty()) {
            res.push_back(layers.front());
            layers.pop();
        }

        return res;
    }
};