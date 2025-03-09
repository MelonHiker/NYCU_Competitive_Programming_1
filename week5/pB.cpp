#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1005;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> w >> h;
    vector<vector<pii>> pos(1000);
    vector<vector<int>> height(h + 2, vector<int>(w + 2, -1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> height[i][j];
            pos[height[i][j]].push_back({i, j});
        }
    }
    
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    vector<vector<char>> used(h + 2, vector<char>(w + 2));
    auto bfs = [&](vector<pii> &st) {
        queue<pii> que;
        for (auto p: st) {
            que.push(p);
            used[p.first][p.second] = true;
        }
        while (!que.empty()) {
            pii p = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (used[nx][ny] || height[nx][ny] < height[p.first][p.second]) {
                    continue;
                }
                que.push({nx, ny});
                used[nx][ny] = true;
            }
        }
    };

    int ans = 0;
    for (int k = 0; k < 1000; k++) {
        vector<pii> st;
        for (auto p: pos[k]) {
            if (used[p.first][p.second]) {
                continue;
            }
            ans++;
            st.push_back(p);
        }
        bfs(st);
    }
    cout << ans << '\n';
}