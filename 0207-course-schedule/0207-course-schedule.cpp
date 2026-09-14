class Solution {
public:
    void solve(vector<vector<int>>& arr, unordered_map<int, vector<int>>& adjLS,
               int V, vector<int>& ans) {
        unordered_map<int, int> inDeg;
        for (auto x : arr) {
            int u = x[0];
            int v = x[1];
            inDeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int fr = q.front();
            q.pop();

            ans.push_back(fr);
            for (auto x : adjLS[fr]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }
    }
    bool canFinish(int V, vector<vector<int>>& arr) {
        unordered_map<int, vector<int>> adjLS;
        for (auto x : arr) {
            int u = x[0];
            int v = x[1];
            adjLS[u].push_back(v);
        }
        vector<int> ans;
        solve(arr, adjLS, V, ans);
        return ans.size() == V;
    }
};