class Solution {
public:
    vector<vector<int>> dir{{0, -1}, {0, 1},  {-1, 0}, {1, 0},
                            {1, 1},  {-1, 1}, {1, -1}, {-1, -1}};
    typedef pair<int, int> P;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0].size() == 0 || grid.empty())
            return 0;
        if (grid[0][0] != 0)
            return -1;

        int r = grid.size();
        int c = grid[0].size();

        queue<P> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int dist = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                if (i == r - 1 && j == c - 1) {
                    return dist;
                }

                for (auto x : dir) {
                    int new_i = x[0] + i;
                    int new_j = x[1] + j;

                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
                        grid[new_i][new_j] == 0) {
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};