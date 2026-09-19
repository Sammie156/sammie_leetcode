enum State {
    UNVISITED,
    VISITING,
    SAFE
};

class Solution {
public:
    bool dfs(
        vector<vector<int>>& graph,
        vector<State>& state,
        int course
    ) {
        if (state[course] == VISITING) {
            return false;
        }
        if (state[course] == SAFE) {
            return true;
        }

        state[course] = VISITING;

        for (int req: graph[course]) {
            if (!dfs(graph, state, req)) {
                return false;
            }
        }

        state[course] = SAFE;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<State> state(numCourses, UNVISITED);

        vector<vector<int>> graph(numCourses);

        // basically the adjacency graph
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, state, i)) {
                return false;
            }
        }

        return true;
    }
};