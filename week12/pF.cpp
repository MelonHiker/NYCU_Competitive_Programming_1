#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int idx = 0;
    map<string, int> tag;
    vector<int> px(n), py(n), poke(n);
    for (int i = 0; i < n; i++) {
        cin >> px[i] >> py[i];
        string name;
        cin >> name;
        if (!tag.count(name)) {
            tag[name] = idx++;
        }
        poke[i] = tag[name];
    }
    
    int ans = INT32_MAX;
    vector<vector<int>> dp(1<<n, vector<int>(n, INF));
    for (int j = 0; j < n; j++) {
        dp[1<<j][j] = abs(px[j]) + abs(py[j]);
    }
    for (int i = 0; i < 1<<n; i++) {
        bool valid = true;
        vector<char> catched(idx);
        for (int j = 0; j < n; j++) {
            if (i>>j & 1) {
                if (catched[poke[j]]) {
                    valid = false;
                    break;
                }
                catched[poke[j]] = true;
            }
        }
        if (!valid) {
            continue;
        }
        bool clear = __builtin_popcount(i) == idx;
        for (int j = 0; j < n; j++) {
            if ((i>>j & 1) == 0) {
                continue;
            }
            if (clear) {
                ans = min(dp[i][j] + abs(px[j]) + abs(py[j]), ans);
                continue;
            }
            for (int k = 0; k < n; k++) {
                if ((i>>k & 1) || catched[poke[k]]) {
                    continue;
                }
                dp[i | (1<<k)][k] = min(dp[i | (1<<k)][k], dp[i][j] + abs(px[j] - px[k]) + abs(py[j] - py[k]));
            }
        }
    }
    cout << ans << '\n';
}