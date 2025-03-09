#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int x, y, d;
    bool operator<(const Node &other) const {
        return d > other.d;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r + 2, vector<int>(c + 2, -1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    priority_queue<Node> pq;
    for (int i = 1; i <= r; i++) {
        pq.push({i, 1, grid[i][1]});
        grid[i][1] = -1;
    }
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        ans = max(ans, node.d);
        if (node.y == c) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i], ny = node.y + dy[i];
            if (grid[nx][ny] == -1) {
                continue;
            }
            pq.push({nx, ny, grid[nx][ny]});
            grid[nx][ny] = -1;
        }
    }
    cout << ans << '\n';
}