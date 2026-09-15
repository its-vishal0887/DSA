class Solution {
public:
    bool dfsHelper(int i, unordered_map<int, vector<int>>& adjLS,
                   unordered_map<int, bool>& vis,
                   unordered_map<int, bool>& path,
                   unordered_map<int, bool>& safe) {
        vis[i] = true;
        path[i] = true;

        for (auto x : adjLS[i]) {
            if (!vis[x]) {
                bool ans = dfsHelper(x, adjLS, vis, path, safe);
                if (ans) {
                    safe[i] = false;
                    path[i] = false;
                    return true;
                }
            } else if (path[x]) {
                safe[i] = false;
                path[i] = false;
                return true;
            } else if (!safe[x]) {
                safe[i] = false;
                path[i] = false;
                return true;
            }
        }
        path[i] = false;
        safe[i] = true;
        return false;
    }

    bool solve(int V, unordered_map<int, vector<int>>& adjLS,
               unordered_map<int, bool>& vis, unordered_map<int, bool>& path,
               unordered_map<int, bool>& safe) {
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool ans = dfsHelper(i, adjLS, vis, path, safe);
                if (ans) {
                    continue;
                }
            }
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& arr) {
        unordered_map<int, vector<int>> adjLS;
        for (int i = 0; i < arr.size(); i++) {
            adjLS[i] = arr[i];
        }
        int V = arr.size();
        unordered_map<int, bool> vis;
        unordered_map<int, bool> path;
        unordered_map<int, bool> safe;

        solve(V, adjLS, vis, path, safe);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};