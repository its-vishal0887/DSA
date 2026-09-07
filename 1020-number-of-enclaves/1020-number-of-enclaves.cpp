class Solution {
public:
    vector<vector<int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    typedef pair<int, int> P;
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid[0].size() == 0 || grid.empty())
            return 0;
        int r = grid.size();
        int c = grid[0].size();

        queue<P> q;
        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if (grid[r - 1][j] == 1) {
                q.push({r - 1, j});
                grid[r - 1][j] = 0;
            }
        }
        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if (grid[i][c - 1] == 1) {
                q.push({i, c - 1});
                grid[i][c - 1] = 0;
            }
        }

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for (auto x : dir) {
                    int new_i = x[0] + i;
                    int new_j = x[1] + j;

                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
                        grid[new_i][new_j] == 1) {
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 0;
                    }
                }
            }
        }
        int one = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    one++;
                }
            }
        }
        return one;
    }
};