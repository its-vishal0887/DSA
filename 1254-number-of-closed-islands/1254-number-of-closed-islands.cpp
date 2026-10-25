class Solution {
public:
    typedef pair<int, int> p;

    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool solve(vector<vector<int>>& arr, int i, int j) {
        int r = arr.size();
        int c = arr[0].size();

        if (arr[i][j] != 0)
            return 0;

        queue<p> q;
        q.push({i, j});
        arr[i][j] = 1;

        bool closed = true;

        while (!q.empty()) {
            p curr = q.front();
            q.pop();

            int prev_i = curr.first;
            int prev_j = curr.second;

            for (auto& x : dir) {
                int new_i = prev_i + x[0];
                int new_j = prev_j + x[1];

                // Island touches outside the grid
                if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c) {
                    closed = false;
                    continue;
                }

                if (arr[new_i][new_j] == 0) {
                    arr[new_i][new_j] = 1;
                    q.push({new_i, new_j});
                }
            }
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                if (arr[i][j] == 0 && solve(arr, i, j)) {
                    // ans = max(ans, solve(arr, i, j));
                    ans++;
                }
            }
        }
        return ans;
    }
};