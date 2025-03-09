#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int c) {
    int n;
    cin >> n;
    vector<ll> weight(n + 1), value(n + 1), dp(c + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> weight[i];
    }

    vector<vector<int>> last(n + 1, vector<int>(c + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= 0; j--) {
            if (j >= weight[i] && dp[j - weight[i]] + value[i] > dp[j]) {
                dp[j] = dp[j - weight[i]] + value[i];
                last[i][j] = i;
            } else {
                last[i][j] = last[i - 1][j];
            }
        }
    }
    vector<int> ans;
    int i = last[n][c];
    while (i) {
        ans.push_back(i);
        c -= weight[i];
        i = last[i - 1][c];
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] - 1 << " \n"[i == 0];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    while (cin >> c) {
        solve(c);
    }
}