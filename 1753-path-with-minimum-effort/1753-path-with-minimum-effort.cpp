class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) return;

        if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else if (rank[root_b] < rank[root_a]) {
            parent[root_b] = root_a;
        } else {
            parent[root_b] = root_a;
            rank[root_a]++;
        }
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<array<int, 3>> edges;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int curr = r * cols + c;

                if (c + 1 < cols) {
                    int next = r * cols + (c + 1);
                    int effort = abs(heights[r][c] - heights[r][c + 1]);

                    edges.push_back({effort, curr, next});
                }

                if (r + 1 < rows) {
                    int next = (r + 1) * cols + c;
                    int effort = abs(heights[r][c] - heights[r + 1][c]);

                    edges.push_back({effort, curr, next});
                }
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(rows * cols);

        int start = 0;
        int end = rows * cols - 1;

        for (auto& edge: edges) {
            int effort = edge[0];
            int u = edge[1];
            int v = edge[2];

            dsu.unite(u, v);

            if (dsu.find(start) == dsu.find(end)) {
                return effort;
            }
        }

        return 0;
    }
};