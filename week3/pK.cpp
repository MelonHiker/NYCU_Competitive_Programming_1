#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1}, dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    auto dfs = [&](auto self, int x, int y, int px=0, int py=0) -> bool {
        grid[x][y] = 'p';
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (grid[nx][ny] == '.' || (nx == px && ny == py)) {
                continue;
            }
            if (grid[nx][ny] == 'p') {
                return true;
            }
            if (self(self, nx, ny, x, y)) {
                return true;
            }
        }
        grid[x][y] = '.';
        return false;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#') {
                ans += (int)dfs(dfs, i, j);
            }
        }
    }
    cout << ans << '\n';
}